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

int readChoice(){
  int choice;
  if(scanf("%d",&choice)!=1){
    printf("\n|||Expected number|||\n\n");
    exit(1);
  }
  else{
    return choice;
  }
}
char showMenu(){
  printf("\n\n              Sorting algorithms          \n");
  printf("1.  Show current array\n");
  printf("2.  Bubble sort\n");
  printf("3.  Insertion sort\n");
  printf("4.  Quicksort\n");
  printf("5.  Quit\n");
  printf("\n");
}
void createArray (int numbers[], int size){
  int i;
  for (i = 0; i<size; i++){
    numbers[i]=rand() % 100 + 1;
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
  double start, end;
  start = (double)clock();
  start = start/(double)CLOCKS_PER_SEC;
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
    end = (double)clock();
    end = end/(double)CLOCKS_PER_SEC;

    printf("Bubble sort done!\n");
    printf("\nSort took %d seconds.\n",end - start);
}
