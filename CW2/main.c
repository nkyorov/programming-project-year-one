#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "prototypes.h"
int main( int argc, char **argv ){
  while(1){
    showMenu();
    int choice = readInput();
    switch (choice) {
      case 1:
        printf("\n");

        //Create the array with size specified by the user
        printf("Array size: ");
        int size = readInput();
  		int *numbers;

  		//Populate the array with random numbers specified by the user
  		printf("Random numbers limit: ");
        int limit = readInput();
		numbers=generateNumbers(size,limit);

        //Do the sort
        double bubbleTime=bubbleSort(numbers,size);
        writeData(bubbleTime);
        //Prevent memory leaks
        free(numbers);
        break;
      case 2:
        printf("\n");

        //Create the array with size specified by the user
        printf("Array size: ");
        size = readInput();

		//Populate the array with random numbers specified by the user
        printf("Random numbers limit: ");
        limit = readInput();
  		numbers=generateNumbers(size,limit);

  		//Do the sort
  		insertionSort(numbers,size);

		//Prevent memory leaks
  		free(numbers);
        break;
      case 3:
      	//Create the array with size specified by the user
        printf("\n");
        printf("Array size: ");
        size = readInput();

        //Populate the array with random numbers specified by the user
        printf("Random numbers limit: ");
        limit = readInput();
  		numbers=generateNumbers(size,limit);

  		//Start the clock for benchmarking purposes
        clock_t start, end;
        start = clock();

        printf("\nYour array is being sorted...\n");
        quickSort(numbers,0,size-1);

        end = clock();
        double quickTime=((double)(end-start))/ CLOCKS_PER_SEC;
        //End clock

        //Return time
        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");

        //Prevent memory leaks
        free(numbers);
        break;
      case 4:
      	//Create the array with size specified by the user
      	printf("\n");
        printf("Array size: ");
        size = readInput();
  		int *numbers_copy;

  		//Populate the array with random numbers specified by the user
  		printf("Random numbers limit: ");
        limit = readInput();
		numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
      	numbers_copy=createArray(size);
      	memcpy(numbers_copy,numbers,size*sizeof(int));

      	//Do the sorts
      	bubbleTime= bubbleSort(numbers,size);
      	double insertionTime=insertionSort(numbers_copy,size);

      	printf("\n");

      	//Compare the times and print which sort is faster
      	if(bubbleTime>insertionTime){
      		printf("Bubble sort is slower by %f seconds.\n",bubbleTime-insertionTime);
      	}
      	if(insertionTime>bubbleTime){
      		printf("Insertion sort is slower by %f seconds\n",insertionTime-bubbleTime);
      	}

      	//Prevent memory leaks
      	free(numbers);
      	free(numbers_copy);
      	break;
      case 5:
		//Create the array with size specified by the user
        printf("\n");
        printf("Array size: ");
        size = readInput();

        //Populate the array with random numbers specified by the user
        printf("Random numbers limit: ");
        limit = readInput();
        numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
        numbers_copy=createArray(size);
        memcpy(numbers_copy,numbers,size*sizeof(int));

        //Do the sort
        bubbleTime= bubbleSort(numbers,size);

        //Start benchmark
        start = clock();

        printf("\nYour array is being sorted...\n");
        quickSort(numbers_copy,0,size-1);

        end = clock();
        quickTime=((double)(end-start))/ CLOCKS_PER_SEC;
        //End benchmark

        //Return captured time
        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");

        //Prevent memory leaks
        free(numbers);
        printf("\n");

        //Compare the sorts and print which is faster
        if(bubbleTime>quickTime){
          printf("Bubble sort is slower by %f seconds.\n",bubbleTime-quickTime);
        }
        if(quickTime>bubbleTime){
          printf("Quick sort is slower by %f seconds\n",quickTime-bubbleTime);
        }
      	break;
      case 6:
      	//Create the array with size specified by the user
        printf("\n");
        printf("Array size: ");
        size = readInput();
        *numbers_copy;

        //Populate the array with random numbers specified by the user
        printf("Random numbers limit: ");
        limit = readInput();
        numbers=generateNumbers(size,limit);

        //Create an exact copy of the array
        numbers_copy=createArray(size);
        memcpy(numbers_copy,numbers,size*sizeof(int));

        //Do the sort on the original's copy
        insertionTime=insertionSort(numbers,size);

        //Start benchmark
        start = (double)clock();
        start = start/(double)CLOCKS_PER_SEC;

  		printf("\nYour array is being sorted...\n");
        quickSort(numbers_copy,0,size-1);

        end = (double)clock();
        end = end/(double)CLOCKS_PER_SEC;
        quickTime=end-start;
        //End benchmark

        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");
        printf("\n");

        //Compare the sorts and show which is faster
        if(quickTime>insertionTime){
          printf("Quick sort is slower by %f seconds.\n",quickTime-insertionTime);
        }
        if(insertionTime>quickTime){
          printf("Insertion sort is slower by %f seconds\n",insertionTime-quickTime);
        }

        //Prevent memory leaks
        free(numbers);
        free(numbers_copy);
      	break;
      case 7:
      	//Create the array with size specified by the user
        printf("\n");
        printf("Array size: ");
        size = readInput();

        //Copies of the original array, which will be used to perform the othet two sorts
        *numbers_copy;
        int *numbers_copy2;

        //Populate the array with random numbers specified by the user
        printf("Random numbers limit: ");
        limit = readInput();
        numbers=generateNumbers(size,limit);

        //Create an exact copy of the array and allocate space
        numbers_copy=createArray(size);
        numbers_copy2=createArray(size);
        memcpy(numbers_copy,numbers,size*sizeof(int));
        memcpy(numbers_copy2,numbers,size*sizeof(int));

        bubbleTime= bubbleSort(numbers,size);
        insertionTime=insertionSort(numbers_copy,size);

        //Start benchmark
        start = clock();

        quickSort(numbers_copy2,0,size-1);
        printf("\nYour array is being sorted...\n");

        end = clock();
        quickTime=((double)(end-start))/ CLOCKS_PER_SEC;
        //End benchmark

        printf("\nSort took %f seconds.\n",quickTime);
        printf("Quick sort done!\n");
        printf("\n\n");


        //Compare the times
        if (bubbleTime<quickTime && bubbleTime<insertionTime){
          printf("Bubble sort is the fastest algorithm.\n");
        }else if (quickTime<bubbleTime && quickTime<insertionTime){
          printf("Quick sort is the fastest algorithm.\n");
        }
        else{
          printf("Insertion sort is the fastest algorithm.\n");
        }



        //Prevent memory leaks
        free(numbers);
        free(numbers_copy);
        free(numbers_copy2);
        break;
      case 99:
      	//Quit
        exit(1);
        break;
      default:
		//Every value other than the specified in the menu
        printf("\n\n***Invalid option***\n\n");
        break;
      }
    }
  return 0;
}
