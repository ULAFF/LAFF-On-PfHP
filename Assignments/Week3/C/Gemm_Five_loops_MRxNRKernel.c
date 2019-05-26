#include <stdio.h>
#include <stdlib.h>

#define alpha( i,j ) A[ (j)*ldA + (i) ]   // map alpha( i,j ) to array A
#define beta( i,j )  B[ (j)*ldB + (i) ]   // map beta( i,j ) to array B
#define gamma( i,j ) C[ (j)*ldC + (i) ]   // map gamma( i,j ) to array C

#define min( x, y ) ( ( x ) < ( y ) ? x : y )

void LoopFive( int, int, int, double *, int, double *, int, double *, int );
void LoopFour( int, int, int, double *, int, double *, int, double *, int );
void LoopThree( int, int, int, double *, int, double *, int, double *, int );
void LoopTwo( int, int, int, double *, int, double *, int, double *, int );
void LoopOne( int, int, int, double *, int, double *, int, double *, int );
void Gemm_MRxNRKernel( int, double *, int, double *, int, double *, int );

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

  LoopFive( m, n, k, A, ldA, B, ldB, C, ldC );
}

void LoopFive( int m, int n, int k, double *A, int ldA,
		   double *B, int ldB, double *C, int ldC )
{
  for ( int j=0; j<n; j+=NC ) {
    int jb = min( NC, n-j );    /* Last loop may not involve a full block */
    LoopFour( m, jb, k, A, ldA, &beta(  ,  ), ldB, &gamma(  ,  ), ldC );
  }
}

void LoopFour( int m, int n, int k, double *A, int ldA, 
	       double *B, int ldB, double *C, int ldC )
{
  for ( int p=0; p<k; p+=KC ) {
    int pb = min( KC, k-p );    /* Last loop may not involve a full block */
    LoopThree( m, n, pb, &alpha(  ,   ), ldA, &beta(  ,  ), ldB, C, ldC );
  }
}

void LoopThree( int m, int n, int k, double *A, int ldA, 
		double *B, int ldB, double *C, int ldC )
{
  for ( int i=0; i<m; i+=MC ) {
    int ib = min( MC, m-i );    /* Last loop may not involve a full block */
    LoopTwo( ib, n, k, &alpha(  ,  ), ldA, B, ldB, &gamma(  ,  ), ldC );
  }
}

void LoopTwo( int m, int n, int k, double *A, int ldA,
	      double *B, int ldB, double *C, int ldC )
{
  for ( int j=0; j<n; j+=NR ) {
    int jb = min( NR, n-j );
    LoopOne( m, jb, k, A, ldA, &beta(  ,  ), ldB, &gamma(  ,  ), ldC );
  }
}

void LoopOne( int m, int n, int k, double *A, int ldA,
	      double *B, int ldB, double *C, int ldC )
{
  for ( int i=0; i<m; i+=MR ) {
    int ib = min( MR, m-i );
    Gemm_MRxNRKernel( k, &alpha(  ,  ), ldA, B, ldB, &gamma(  ,  ), ldC );
  }
}

