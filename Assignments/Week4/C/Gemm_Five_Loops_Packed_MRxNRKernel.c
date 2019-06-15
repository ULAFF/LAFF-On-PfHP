#include <stdio.h>
#include <stdlib.h>

#include<immintrin.h>

#define alpha( i,j ) A[ (j)*ldA + (i) ]   // map alpha( i,j ) to array A
#define beta( i,j )  B[ (j)*ldB + (i) ]   // map beta( i,j ) to array B
#define gamma( i,j ) C[ (j)*ldC + (i) ]   // map gamma( i,j ) to array C

#define min( x, y ) ( ( x ) < ( y ) ? x : y )

void LoopFive( int, int, int, double *, int, double *, int, double *, int );
void LoopFour( int, int, int, double *, int, double *, int,  double *, int );
void LoopThree( int, int, int, double *, int, double *, double *, int );
void LoopTwo( int, int, int, double *, double *, double *, int );
void LoopOne( int, int, int, double *, double *, double *, int );
void Gemm_MRxNRKernel_Packed( int, double *, double *, double *, int );
void PackBlockA_MCxKC( int, int, double *, int, double * );
void PackPanelB_KCxNC( int, int, double *, int, double * );
  
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
    LoopFour( m, jb, k, A, ldA, &beta( 0,j ), ldB, &gamma( 0,j ), ldC );
  } 
}

void LoopFour( int m, int n, int k, double *A, int ldA, double *B, int ldB,
	       double *C, int ldC )
{
  double *Btilde = ( double * ) _mm_malloc( KC * NC * sizeof( double ), 64 );
  
  for ( int p=0; p<k; p+=KC ) {
    int pb = min( KC, k-p );    /* Last loop may not involve a full block */
    PackPanelB_KCxNC( pb, n, &beta( p, 0 ), ldB, Btilde );
    LoopThree( m, n, pb, &alpha( 0, p ), ldA, Btilde, C, ldC );
  }

  _mm_free( Btilde); 
}

void LoopThree( int m, int n, int k, double *A, int ldA, double *Btilde, double *C, int ldC )
{
  double *Atilde = ( double * ) _mm_malloc( MC * KC * sizeof( double ), 64 );
       
  for ( int i=0; i<m; i+=MC ) {
    int ib = min( MC, m-i );    /* Last loop may not involve a full block */
    PackBlockA_MCxKC( ib, k, &alpha( i, 0 ), ldA, Atilde );
    LoopTwo( ib, n, k, Atilde, Btilde, &gamma( i,0 ), ldC );
  }

  _mm_free( Atilde);
}

void LoopTwo( int m, int n, int k, double *Atilde, double *Btilde, double *C, int ldC )
{
  for ( int j=0; j<n; j+=NR ) {
    int jb = min( NR, n-j );
    LoopOne( m, jb, k, Atilde, &Btilde[ j*k ], &gamma( 0,j ), ldC );
  }
}

void LoopOne( int m, int n, int k, double *Atilde, double *MicroPanelB, double *C, int ldC )
{
  for ( int i=0; i<m; i+=MR ) {
    int ib = min( MR, m-i );
    Gemm_MRxNRKernel_Packed( k, &Atilde[ i*k ], MicroPanelB, &gamma( i,0 ), ldC );
  }
}

