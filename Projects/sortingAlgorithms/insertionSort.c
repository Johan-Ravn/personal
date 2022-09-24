#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randomNum(int maxNum)
{
    return (rand()%maxNum);
}

void addArray(int* randomArray, int arrayLength, int maxNum)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        randomArray[i] = randomNum(maxNum);
    }
}

void printArray(int arrayLength, int* randomArray, int sortedOrNot)
{
    if (sortedOrNot == 0)
    {
        printf("\nUnsorted list:\n");
        for (int j = 0; j < arrayLength; ++j)
        {
            printf("\nRandom array[%d]: %d", j + 1, randomArray[j]);
        }
    }
    else if (sortedOrNot == 1)
    {
        printf("\n Sorted list:\n");
        for (int j = 0; j < arrayLength; ++j)
        {
            printf("\nRandom array[%d]: %d", j + 1, randomArray[j]);
        }
    }
}

void makeList(int arrayLength, int* randomArray, int maxNum)
{
    addArray(randomArray, arrayLength, maxNum);
    printArray(arrayLength, randomArray, 0);
}

void insertionSort(int* randomArray, int arrayLength)
{
    for (int i = 1; i < arrayLength; ++i)
    {
        int num = randomArray[i];
        int j = i - 1;

        while (j >= 0 && randomArray[j] > num)
        {
            randomArray[j + 1] = randomArray[j];
            --j;
        }
        randomArray[j + 1] = num;
    }
    printArray(arrayLength, randomArray, 1);
}

void main()
{
    int randomArray[100000] = {0}, arrayLength = sizeof(randomArray) / sizeof(randomArray[0]), maxNum = arrayLength * 2;
    makeList(arrayLength, randomArray, maxNum);
    insertionSort(randomArray, arrayLength);
}
