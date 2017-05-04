#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "prototypes.h"
int main( int argc, char **argv ){
	if (argc>1){
		fprintf(stderr, "Usage is ./Sort\n");
		exit(1);
	}

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

				//Display the array
				displayArray(numbers,size);

				//Do the sort
				double bubbleTime=bubbleSort(numbers,size);

				//Display array
				displayArray(numbers,size);

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

				//Display the array
				displayArray(numbers,size);

				//Do the sort
				insertionSort(numbers,size);

				//Display array
				displayArray(numbers,size);
				    
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

				//Display the array
				displayArray(numbers,size);

				//Start the clock for benchmarking purposes
				clock_t start, end;
				start = clock();

				printf("\nYour array is being sorted...\n");
				quickSort(numbers,0,size-1);

				end = clock();
				double quickTime=((double)(end-start))/ CLOCKS_PER_SEC;
				//End clock

				//Display array
				displayArray(numbers,size);

				//Return time
				printf("\nSort took %f seconds.\n",quickTime);
				printf("Quick sort done!\n");

				//Prevent memory leaks
				free(numbers);
				break;
			case 4:
				//Empty previous data
				clearData();

				//Create the array with size specified by the user
				printf("\n");
				printf("Array size: ");
				size = readInput();
				int *numbers_copy;

				//Populate the array with random numbers specified by the user
				printf("Random numbers limit: ");
				limit = readInput();
				numbers=generateNumbers(size,limit);

				//Display the array
				displayArray(numbers,size);

				//Create an exact copy of the array
				numbers_copy=createArray(size);
				memcpy(numbers_copy,numbers,size*sizeof(int));

				//Do the sorts
				bubbleTime= bubbleSort(numbers,size);
				double insertionTime=insertionSort(numbers_copy,size);

				printf("\n");

				//Display array
				displayArray(numbers,size);

				//Compare the times and print which sort is faster
				if(bubbleTime>insertionTime){
					printf("Bubble sort is slower by %f seconds.\n",bubbleTime-insertionTime);
				}
				if(insertionTime>bubbleTime){
					printf("Insertion sort is slower by %f seconds\n",insertionTime-bubbleTime);
				}

				writeData("Insertionsort",insertionTime);
				writeData("Bubblesort",bubbleTime);

				//Invoke gnuplot
				system("gnuplot -p data.gnu");
					
				//Prevent memory leaks
				free(numbers);
				free(numbers_copy);
				break;
			case 5:
				//Empty previous data
				clearData();

				//Create the array with size specified by the user
				printf("\n");
				printf("Array size: ");
				size = readInput();

				//Populate the array with random numbers specified by the user
				printf("Random numbers limit: ");
				limit = readInput();
				numbers=generateNumbers(size,limit);

				//Display the array
				displayArray(numbers,size);

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

				//Display array
				displayArray(numbers,size);

				//Compare the sorts and print which is faster
				if(bubbleTime>quickTime){
				  printf("Bubble sort is slower by %f seconds.\n",bubbleTime-quickTime);
				}
				if(quickTime>bubbleTime){
				  printf("Quick sort is slower by %f seconds\n",quickTime-bubbleTime);
				}

				writeData("Quicksort",quickTime);
				writeData("Bubblesort",bubbleTime);
					
				//Invoke gnuplot
				system("gnuplot -p data.gnu");
				break;
			case 6:
				//Empty previous data
				clearData();
					
				//Create the array with size specified by the user
				printf("\n");
				printf("Array size: ");
				size = readInput();
				*numbers_copy;

				//Populate the array with random numbers specified by the user
				printf("Random numbers limit: ");
				limit = readInput();
				numbers=generateNumbers(size,limit);

				//Display the array
				displayArray(numbers,size);

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

				//Display array
				displayArray(numbers,size);

				//Compare the sorts and show which is faster
				if(quickTime>insertionTime){
				  printf("Quick sort is slower by %f seconds.\n",quickTime-insertionTime);
				}
				if(insertionTime>quickTime){
				  printf("Insertion sort is slower by %f seconds\n",insertionTime-quickTime);
				}

				writeData("Quicksort",quickTime);
				writeData("Insertionsort",insertionTime);

				//Invoke gnuplot
				system("gnuplot -p data.gnu");

				//Prevent memory leaks
				free(numbers);
				free(numbers_copy);
				break;
			case 7:
				//Empty previous data
				clearData();

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

				//Display the array
				displayArray(numbers,size);
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

				//Display array
				displayArray(numbers,size);

				//Compare the times
				if (bubbleTime<quickTime && bubbleTime<insertionTime){
				  printf("\nBubble sort is the fastest algorithm.\n\n");
				}else if (quickTime<bubbleTime && quickTime<insertionTime){
				  printf("\nQuick sort is the fastest algorithm.\n\n");
				}
				else{
				  printf("\nInsertion sort is the fastest algorithm.\n\n");
				}

				writeData("Quicksort",quickTime);
				writeData("Insertionsort",insertionTime);
				writeData("Bubblesort",bubbleTime);

				//Invoke gnuplot
				system("gnuplot -p data.gnu");

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
