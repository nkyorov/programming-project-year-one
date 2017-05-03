#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
//Takes user input
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

//Swaps two values
void swap(int *firstElement, int *secondElement){
  int temp = *firstElement;
  *firstElement = *secondElement;
  *secondElement = temp;
}

//In case malloc is unsuccessfull
void memError(){
  fprintf(stderr,"\n*******Out of memory*******\n");
  exit(1);
}

//Creates dynamic array given size
int *createArray(int size){
  int i = 0;
  int *arrayPtr;
  if (size<0){
    memError();
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

//Populates the array with random numbers between the set limit
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

//Print out the menu
char showMenu(){
  printf("\n\n              Sorting algorithms          \n");
  printf("1.  Bubble sort\n");
  printf("2.  Insertion sort\n");
  printf("3.  Quicksort\n");
  printf("4.  Compare Bubble sort and Insertion sort\n");
  printf("5.  Compare Bubble sort and Quicksort\n");
  printf("6.  Compare Insertion sort and Quicksort\n");
  printf("7.  Compare Insertion sort, Bubble sort and Quicksort\n");
  printf("\n");
  printf("99.  Quit\n");
  printf("\n");
}

//Prints out the array
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

//Writes benchmarking times to a file
void writeData(char *sort,double data){
  FILE *fp = fopen("data.out","a+");
  fprintf(fp,"%s\t%f\n",sort,data);  
  fclose(fp);
  return;
}

//Deletes the file
void clearData(){
  char fileName[]="data.out";  
  remove(fileName);
  return;
}