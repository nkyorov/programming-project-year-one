#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

  arrayPtr = (int *)malloc(sizeof(int)*size);

  if(arrayPtr != NULL){
    for(i = 0; i < size; i++){
      arrayPtr[i] = 0;
    }
  }
  return arrayPtr;
}

int *generateNumbers(int size, int limit){
  int *arrayPtr = createArray(size);
  int j = 0;
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
    if(i%10 == 0 && i>0){
      printf("\n");
    }

    printf(" %d ",numbers[i]);
  }
}

void bubbleSort(int numbers[], int size){
  double start, end;
  start = (double)clock();
  start = start/(double)CLOCKS_PER_SEC;
  int i;
  int j;
  int temp;
  size = size - 1;
  printf("\nYour array is being sorted...\n");
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
  printf("\nSort took %f seconds.\n",end - start);
  printf("Bubble sort done!\n");
}

void insertionSort(int numbers[], int size){
  double start, end;
  start = (double)clock();
  start = start/(double)CLOCKS_PER_SEC;
  int i;
  int j;
  int temp;
  printf("\nYour array is being sorted...\n");
  for(i=0; i<size; i++){
  	temp = numbers[i];
  	j=i-1;
  	while(temp<numbers[j] && j>=0){
  		numbers[j+1] = numbers[j];
  		j=j-1;
  	}
  	numbers[j+1]=temp;
  }
  end = (double)clock();
  end = end/(double)CLOCKS_PER_SEC;
  printf("\nSort took %f seconds.\n",end - start);
  printf("Insertion sort done!\n");
}