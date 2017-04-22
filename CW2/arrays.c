#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
int readInput(){
    int input;
    if(scanf("%d",&input)!=1){
        printf("\n|||Expected number|||\n\n");
        exit(1);
    }
    else{
        return input;
    }
}

int *createArray(int size){
    int i = 0;
    int *arrayPtr;
    if (size<0){
        printf("Size cannot be negative number");
        exit(1);
    }
    else{
        arrayPtr = (int *)malloc(sizeof(int)*size);
        printf("\nCreating array...\n");
        if(arrayPtr != NULL){
            for(i = 0; i < size; i++){
                arrayPtr[i] = 0;
            }
        }
    }
  return arrayPtr;
}


int *generateNumbers(int size, int limit){
  int *arrayPtr = createArray(size);
  int j = 0;
  printf("\nGenerating numbers...\n");
  if(arrayPtr != NULL){
    for(j = 0; j < size; j++){
      arrayPtr[j] = rand() % limit + 1;
    }
  }
  return arrayPtr;
}

char showMenu(){
  printf("\n\n              Sorting algorithms          \n");
  printf("1.  Bubble sort\n");
  printf("2.  Insertion sort\n");
  printf("3.  Quicksort\n");
  printf("4.  Compare Bubble sort and Insertion sort\n");
  printf("5.  Compare Bubble sort and Quicksort\n");
  printf("6.  Compare Insertion sort and Quicksort\n");
  printf("7.  Quit\n");
  printf("\n");
}

void displayArray(int numbers[], int size){
  int i;
  printf("\nArray:\n");
  for (i = 0; i<size; i++){
    if(i%16 == 0 && i>0){
      printf("\n");
    }

    printf(" %d ",numbers[i]);
  }
}

