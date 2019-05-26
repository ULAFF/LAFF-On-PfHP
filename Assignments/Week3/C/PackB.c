#define beta( i,j )  B[ (j)*ldB + (i) ]   // map beta( i,j ) to array B

#define min( x, y ) ( ( x ) < ( y ) ? x : y )

void PackMicroPanelB_KCxNR( int k, int n, double *B, int ldB, double *Btilde )
/* Pack a micro-panel of B into buffer pointed to by Btilde. 
   This is an unoptimized implementation for general KC and NR. */
{
  /* March through B in row-major order, packing into Btilde as we go. */

  if ( n == NR ) /* Full column width micro-panel.*/
    for ( int p=0; p<k; p++ ) 
      for ( int j=0; j<NR; j++ )
	*Btilde++ = beta( p, j );
  else /* Not a full row size micro-panel.  We pad with zeroes. */
    for ( int p=0; p<k; p++ ) {
      for ( int j=0; j<n; j++ )
	*Btilde++ = beta( p, j );
      for ( int j=n; j<NR; j++ )
	*Btilde++ = 0.0;
    }
}

void PackPanelB_KCxNC( int k, int n, double *B, int ldB, double *Btilde )
/* Pack a KC x NC panel of B.  NC is assumed to be a multiple of NR.  The block is 
   packed into Btilde a micro-panel at a time. If necessary, the last micro-panel 
   is padded with columns of zeroes. */
{
  for ( int j=0; j<n; j+= NR ){
    int jb = min( NR, n-j );
    
    PackMicroPanelB_KCxNR( k, jb, &beta( 0, j ), ldB, Btilde );
    Btilde += k * jb;
  }
}

