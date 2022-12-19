
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randomNum(int maxNum);
void addArray(int* randomArray, int arrayLength, int maxNum);
void printArray(int arrayLength, int* randomArray, int sortedOrNot);
void makeList(int arrayLength, int* randomArray, int maxNum);
void insertionSort(int* randomArray, int arrayLength);

#endif
