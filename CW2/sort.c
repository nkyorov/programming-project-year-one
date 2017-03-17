#include <stdio.h>
#include <stdlib.h>
void createArray (int numbers[], int size){
  int i;
  for (i = 0; i<size; i++){
    numbers[i]=rand() % 100;
  }
}


void displayArray(int numbers[], int size){
  int i;
  printf("Array:\n");
  printf("[");
  for (i = 0; i<size; i++){
    printf(" %d ",numbers[i]);
  }
  printf("]\n\n");
}

int main( int argc, char **argv ){
  int size=5;
  int numbers[size];
  createArray(numbers,size);
  displayArray(numbers,size);

  return 0;
}