#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main( int argc, char **argv ){
  int size = readSize();;
  int numbers[size];

  createArray(numbers,size);
  displayArray(numbers,size);

  bubbleSort(numbers,size);
  displayArray(numbers,size);

  return 0;
}
