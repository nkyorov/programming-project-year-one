#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototypes.h"
int readSize(){
  printf("Size of array:\n");
  int size;
  if(scanf("%d",&size)!=1){
    printf("\n|||Expected number|||\n\n");
    exit(1);
  }
  else{
    return size;
  }
}
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

void bubbleSort(int numbers[], int size){
    int i;
    int j;
    int temp;
    size = size - 1;
    for(i=0; i<size; i++){
      for(j=0; j<size-i; j++){
        if(numbers[j]>numbers[j+1]){
          temp = numbers[j+1];
          numbers[j+1] = numbers[j];
          numbers[j] = temp;
        }
      }
    }
    printf("Bubble sort done!\n");
}
