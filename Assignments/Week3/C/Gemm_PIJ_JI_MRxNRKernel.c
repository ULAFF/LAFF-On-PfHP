#include <stdio.h>
#include <stdlib.h>

#define alpha( i,j ) A[ (j)*ldA + (i) ]   // map alpha( i,j ) to array A
#define beta( i,j )  B[ (j)*ldB + (i) ]   // map beta( i,j ) to array B
#define gamma( i,j ) C[ (j)*ldC + (i) ]   // map gamma( i,j ) to array C

#define min( x, y )  ( (x) < (y) ? x : y )

void Gemm_MRxNRKernel( int, double *, int, double *, int,
		      double *, int );

void Gemm_JI_MRxNRKernel( int, int, int, double *, int, double *, int,
		        double *, int );

#define MC 96
#define NC 96
#define KC 96

void MyGemm( int m, int n, int k, double *A, int ldA,
	     double *B, int ldB, double *C, int ldC )
{
  if ( m % MR != 0 || MC % MR != 0 ){
    printf( "m and MC must be multiples of MR\n" );
    exit( 0 );
  }
  if ( n % NR != 0 || NC % NR != 0 ){
    printf( "n and NC must be multiples of NR\n" );
    exit( 0 );
  }
  
  for ( int p=0; p<k; p+=KC ) {
    int pb = min( KC, k-p );        /* Last block may not be a full block */
    for ( int i=0; i<m; i+=MC ) {
      int ib = min( MC, m-i );        /* Last block may not be a full block */
      for ( int j=0; j<n; j+=NC ) {
	int jb = min( NC, n-j );        /* Last block may not be a full block */
        Gemm_JI_MRxNRKernel
          ( ib, jb, pb, &alpha( i,p ), ldA, &beta( p,j ), ldB, &gamma( i,j ), ldC );
      }
    }
  }
}

void Gemm_JI_MRxNRKernel( int m, int n, int k, double *A, int ldA,
                                  double *B, int ldB, double *C, int ldC )
{
  for ( int j=0; j<n; j+=NR ) /* n is assumed to be a multiple of NR */
    for ( int i=0; i<m; i+=MR ) /* m is assumed to be a multiple of MR */
      Gemm_MRxNRKernel( k, &alpha( i,0 ), ldA, &beta( 0,j ), ldB, &gamma( i,j ), ldC );
}

