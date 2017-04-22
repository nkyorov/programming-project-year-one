#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "prototypes.h"
double bubbleSort(int numbers[], int size){
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
  double bubbleTime=end-start;
  printf("\nSort took %f seconds.\n",bubbleTime);
  printf("Bubble sort done!\n");
  return bubbleTime;
}

double insertionSort(int numbers[], int size){
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
  double insertionTime=end-start;
  printf("\nSort took %f seconds.\n",insertionTime);
  printf("Insertion sort done!\n");
  return insertionTime;
}

