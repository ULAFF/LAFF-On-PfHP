#define alpha( i,j ) A[ (j)*ldA + (i) ]   // map alpha( i,j ) to array A
#define beta( i,j )  B[ (j)*ldB + (i) ]   // map beta( i,j ) to array B
#define gamma( i,j ) C[ (j)*ldC + (i) ]   // map gamma( i,j ) to array C

#include<immintrin.h>

void Gemm_MRxNRKernel_Packed( int k,
		        double *MP_A, double *MP_B, double *C, int ldC )
{
  __m256d gamma_0123_0 = _mm256_loadu_pd( &gamma( 0,0 ) );
  __m256d gamma_0123_1 = _mm256_loadu_pd( &gamma( 0,1 ) );
  __m256d gamma_0123_2 = _mm256_loadu_pd( &gamma( 0,2 ) );
  __m256d gamma_0123_3 = _mm256_loadu_pd( &gamma( 0,3 ) );
  __m256d gamma_0123_4 = _mm256_loadu_pd( &gamma( 0,4 ) );
  __m256d gamma_0123_5 = _mm256_loadu_pd( &gamma( 0,5 ) );
  __m256d gamma_4567_0 = _mm256_loadu_pd( &gamma( 4,0 ) );
  __m256d gamma_4567_1 = _mm256_loadu_pd( &gamma( 4,1 ) );
  __m256d gamma_4567_2 = _mm256_loadu_pd( &gamma( 4,2 ) );
  __m256d gamma_4567_3 = _mm256_loadu_pd( &gamma( 4,3 ) );
  __m256d gamma_4567_4 = _mm256_loadu_pd( &gamma( 4,4 ) );
  __m256d gamma_4567_5 = _mm256_loadu_pd( &gamma( 4,5 ) );

  __m256d beta_p_j;
   	
  for ( int p=0; p<k; p++ ){
    /* load alpha( 0:11, p ) */
    __m256d alpha_0123_p = _mm256_loadu_pd( MP_A );
    __m256d alpha_4567_p = _mm256_loadu_pd( MP_A+4 );
    /* load beta( p, 0 ); update gamma( 0:7, 0 ) */
    beta_p_j = _mm256_broadcast_sd( MP_B );
    gamma_0123_0 = _mm256_fmadd_pd( alpha_0123_p, beta_p_j, gamma_0123_0 );
    gamma_4567_0 = _mm256_fmadd_pd( alpha_4567_p, beta_p_j, gamma_4567_0 );
    /* load beta( p, 1 ); update gamma( 0:7, 1 ) */
    beta_p_j = _mm256_broadcast_sd( MP_B+1 );
    gamma_0123_1 = _mm256_fmadd_pd( alpha_0123_p, beta_p_j, gamma_0123_1 );
    gamma_4567_1 = _mm256_fmadd_pd( alpha_4567_p, beta_p_j, gamma_4567_1 );
    /* load beta( p, 2 ); update gamma( 0:7, 2 ) */
    beta_p_j = _mm256_broadcast_sd( MP_B+2 );
    gamma_0123_2 = _mm256_fmadd_pd( alpha_0123_p, beta_p_j, gamma_0123_2 );
    gamma_4567_2 = _mm256_fmadd_pd( alpha_4567_p, beta_p_j, gamma_4567_2 );
    /* load beta( p, 3 ); update gamma( 0:7, 3 ) */
    beta_p_j = _mm256_broadcast_sd( MP_B+3 );
    gamma_0123_3 = _mm256_fmadd_pd( alpha_0123_p, beta_p_j, gamma_0123_3 );
    gamma_4567_3 = _mm256_fmadd_pd( alpha_4567_p, beta_p_j, gamma_4567_3 );
    /* load beta( p, 4 ); update gamma( 0:7, 4 ) */
    beta_p_j = _mm256_broadcast_sd( MP_B+4 );
    gamma_0123_4 = _mm256_fmadd_pd( alpha_0123_p, beta_p_j, gamma_0123_4 );
    gamma_4567_4 = _mm256_fmadd_pd( alpha_4567_p, beta_p_j, gamma_4567_4 );
    /* load beta( p, 5 ); update gamma( 0:7, 5 ) */
    beta_p_j = _mm256_broadcast_sd( MP_B+5 );
    gamma_0123_5 = _mm256_fmadd_pd( alpha_0123_p, beta_p_j, gamma_0123_5 );
    gamma_4567_5 = _mm256_fmadd_pd( alpha_4567_p, beta_p_j, gamma_4567_5 );

    MP_A += MR;
    MP_B += NR;
  }

  /* Store the updated results.  This should be done more carefully since
     there may be an incomplete micro-tile. */
  _mm256_storeu_pd( &gamma(0,0), gamma_0123_0 );
  _mm256_storeu_pd( &gamma(4,0), gamma_4567_0 );
  _mm256_storeu_pd( &gamma(0,1), gamma_0123_1 );
  _mm256_storeu_pd( &gamma(4,1), gamma_4567_1 );
  _mm256_storeu_pd( &gamma(0,2), gamma_0123_2 );
  _mm256_storeu_pd( &gamma(4,2), gamma_4567_2 );
  _mm256_storeu_pd( &gamma(0,3), gamma_0123_3 );
  _mm256_storeu_pd( &gamma(4,3), gamma_4567_3 );
  _mm256_storeu_pd( &gamma(0,4), gamma_0123_4 );
  _mm256_storeu_pd( &gamma(4,4), gamma_4567_4 );
  _mm256_storeu_pd( &gamma(0,5), gamma_0123_5 );
  _mm256_storeu_pd( &gamma(4,5), gamma_4567_5 );
}
