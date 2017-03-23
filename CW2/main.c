#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main( int argc, char **argv ){
  int size = readSize();
  int numbers[size];
  createArray(numbers,size);
  while(1){
  showMenu();
  int choice = readChoice();
  switch (choice) {
    case 1:
      printf("\n");
      displayArray(numbers,size);
      break;
    case 2:
      printf("\n");
      bubbleSort(numbers,size);
      displayArray(numbers,size);
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      exit(1);
      break;
    default:
      printf("\n\n***Invalid option***\n\n");
      break;
  }
}
  return 0;
}
