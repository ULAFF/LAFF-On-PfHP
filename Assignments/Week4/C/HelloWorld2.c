#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main(int argc, char *argv[])
{
  #pragma omp parallel
  printf( "Hello World!\n" );
}
