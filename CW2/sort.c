#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv ){
  int i;
  int size = 5;
  int numbers[size];
  printf("Array:\n");
  printf("[");
  for (i = 0; i<size; i++){
    printf(" %d ",numbers[i]);
    numbers[i]=rand() % 100;
  }
  printf("]\n\n");

  return 0;
}
