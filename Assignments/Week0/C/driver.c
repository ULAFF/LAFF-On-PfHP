#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "omp.h"

int main(int argc, char *argv[])
{
  #pragma omp parallel
  printf("Hello World\n");
  
  exit(0);
}
