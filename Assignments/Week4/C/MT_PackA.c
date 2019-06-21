#define alpha( i,j ) A[ (j)*ldA + (i) ]   // map alpha( i,j ) to array A

#define min( x, y ) ( (x) < (y) ? (x) : (y) )

void PackMicroPanelA_MRxKC( int m, int k, double *A, int ldA, double *Atilde )
/* Pack a micro-panel of A into buffer pointed to by Atilde. 
   This is an unoptimized implementation for general MR and KC. */
{
  /* March through A in column-major order, packing into Atilde as we go. */

  if ( m == MR )   /* Full row size micro-panel.*/
    for ( int p=0; p<k; p++ ) 
      for ( int i=0; i<MR; i++ )
	*Atilde++ = alpha( i, p );
  else /* Not a full row size micro-panel.  To be implemented */
    {
    }
}

void PackBlockA_MCxKC( int m, int k, double *A, int ldA, double *Atilde )
/* Pack a MC x KC block of A.  MC is assumed to be a multiple of MR.  The block is 
   packed into Atilde a micro-panel at a time. If necessary, the last micro-panel 
   is padded with rows of zeroes. */
{
  for ( int i=0; i<m; i+= MR ){
    int ib = min( MR, m-i );
    PackMicroPanelA_MRxKC( ib, k, &alpha( i, 0 ), ldA, Atilde );
    Atilde += ib * k;
  }
}
