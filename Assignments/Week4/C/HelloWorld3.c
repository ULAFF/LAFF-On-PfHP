#include <stdio.h>
#include <stdlib.h>

#include "omp.h"

int main(int argc, char *argv[])
{
  int maxthreads = omp_get_max_threads();

  #pragma omp parallel
  {
    int nthreads = omp_get_num_threads(); 
    int tid = omp_get_thread_num(); 

    printf( "Hello World! from %d of %d max_threads = %d \n\n\n", tid, nthreads, maxthreads );
  }
}
