#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

  		  free(numbers);
        break;
      case 3:
        printf("\n");
        printf("Array size: ");
        size = readInput();

        printf("Random numbers limit: ");
        limit = readInput();
  		  numbers=generateNumbers(size,limit);

        double start, end;
        start = (double)clock();
        start = start/(double)CLOCKS_PER_SEC;

        quickSort(numbers,0,size-1);

        end = (double)clock();
        end = end/(double)CLOCKS_PER_SEC;
        double quickTime=end-start;

        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");

        free(numbers);
        break;
      case 4:
      	printf("\n");
        printf("Array size: ");
        size = readInput();
  		  int *numbers_copy;

  		  printf("Random numbers limit: ");
        limit = readInput();
		    numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
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
        printf("\n");
        printf("Array size: ");
        size = readInput();

        printf("Random numbers limit: ");
        limit = readInput();
        numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
        numbers_copy=createArray(size);
        memcpy(numbers_copy,numbers,size*sizeof(int));

        bubbleTime= bubbleSort(numbers,size);


        start = (double)clock();
        start = start/(double)CLOCKS_PER_SEC;

        quickSort(numbers_copy,0,size-1);

        end = (double)clock();
        end = end/(double)CLOCKS_PER_SEC;
        quickTime=end-start;

        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");

        free(numbers);
        printf("\n");

        if(bubbleTime>quickTime){
          printf("Bubble sort is slower by %f seconds.\n",bubbleTime-quickTime);
        }
        if(quickTime>bubbleTime){
          printf("Quick sort is slower by %f seconds\n",quickTime-bubbleTime);
        }
      	break;
      case 6:
        printf("\n");
        printf("Array size: ");
        size = readInput();
        *numbers_copy;

        printf("Random numbers limit: ");
        limit = readInput();
        numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
        numbers_copy=createArray(size);
        memcpy(numbers_copy,numbers,size*sizeof(int));

        insertionTime=insertionSort(numbers_copy,size);
        start = (double)clock();
        start = start/(double)CLOCKS_PER_SEC;

        quickSort(numbers_copy,0,size-1);

        end = (double)clock();
        end = end/(double)CLOCKS_PER_SEC;
        quickTime=end-start;

        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");
        printf("\n");

        if(quickTime>insertionTime){
          printf("Quick sort is slower by %f seconds.\n",quickTime-insertionTime);
        }
        if(insertionTime>quickTime){
          printf("Insertion sort is slower by %f seconds\n",insertionTime-quickTime);
        }


        free(numbers);
        free(numbers_copy);
      	break;
      case 7:
        printf("\n");
        printf("Array size: ");
        size = readInput();
        *numbers_copy;
        int *numbers_copy2;

        printf("Random numbers limit: ");
        limit = readInput();
        numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
        numbers_copy=createArray(size);
        numbers_copy2=createArray(size);
        memcpy(numbers_copy,numbers,size*sizeof(int));
        memcpy(numbers_copy2,numbers,size*sizeof(int));


        bubbleTime= bubbleSort(numbers,size);
        insertionTime=insertionSort(numbers_copy,size);
        start = (double)clock();
        start = start/(double)CLOCKS_PER_SEC;

        quickSort(numbers_copy2,0,size-1);

        end = (double)clock();
        end = end/(double)CLOCKS_PER_SEC;
        quickTime=end-start;

        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");
        printf("\n");


        printf("\n");

        if(quickTime>insertionTime){
          if(quickTime>bubbleTime){
            printf("Quick sort is the fastest of them all\n");
          } else{
            printf("Bubble sort is the fastest of them all\n");
          }
        } else if(insertionTime>bubbleTime){
          printf("Insertion sort is the fastest of them all\n");
        } else{
          printf("Bubble sort is the fastest of them all\n");
        }


        free(numbers);
        free(numbers_copy);
        free(numbers_copy2);
        break;
      case 8:
        exit(1);
        break;
      default:
        printf("\n\n***Invalid option***\n\n");
        break;
      }
    }
  return 0;
}
