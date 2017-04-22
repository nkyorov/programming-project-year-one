#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
int main( int argc, char **argv ){
  while(1){
    showMenu();
    int choice = readInput();
    switch (choice) {
      case 1:
        printf("\n");
        printf("Array size: ");
        int size = readInput();
  		int *numbers;
  		
  		printf("Random numbers limit: ");
        int limit = readInput();
		numbers=generateNumbers(size,limit);

        bubbleSort(numbers,size);
        displayArray(numbers,size);
        free(numbers);
        break;
      case 2:
        printf("\n");
        printf("Array size: ");
        size = readInput();

        printf("Random numbers limit: ");
        limit = readInput();
  		numbers=generateNumbers(size,limit);

  		insertionSort(numbers,size);
  		displayArray(numbers,size);
  		free(numbers);      
        break;
      case 3:
        printf("\n");
        printf("Array size: ");
        size = readInput();

        printf("Random numbers limit: ");
        limit = readInput();
  		numbers=generateNumbers(size,limit);      
        break;
      case 4:
      	printf("\n");
        printf("Array size: ");
        size = readInput();
  		int *numbers_copy;

  		printf("Random numbers limit: ");
        limit = readInput();
		numbers=generateNumbers(size,limit);
      	
      	numbers_copy=createArray(size);
      	memcpy(numbers_copy,numbers,size*sizeof(int));
      	double bubbleTime= bubbleSort(numbers,size);
      	double insertionTime=insertionSort(numbers_copy,size);

      	printf("\n");
      	
      	if(bubbleTime>insertionTime){
      		printf("Bubble sort is slower by %f seconds.\n",bubbleTime-insertionTime);
      	}
      	if(insertionTime>bubbleTime){
      		printf("Insertion sort is slower by %f seconds\n",insertionTime-bubbleTime);
      	}

      	free(numbers);
      	free(numbers_copy);
      	break;
      case 5:
      	break;
      case 6:
      	break;
      case 7:
        exit(1);
        break;
      default:
        printf("\n\n***Invalid option***\n\n");
        break;
      }
    }
  return 0;
}