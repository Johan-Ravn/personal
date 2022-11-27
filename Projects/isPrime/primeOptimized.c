#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int askInput()
{
    while (1)
    {
        int num = -1;
        printf("Max val?: \n");
        scanf("%d", &num);
        if (num > 1)
        {
            return num;
        }
    }
}

int find_divisor(int number)
{
    return ceil(sqrt(number));
}

int prime(int num, int divisor)
{
    if (divisor == 1)
    {
        return 1;
    }
    else if (num % 2 == 0 && num != 2)
    {
        return 0;
    }
    else if (num % divisor == 0)
    {
        return 0;
    }
    return prime(num, divisor - 1);
}

int main(void)
{
    int maxNum = 1000; // askInput();
    int *primes = (int *)malloc(maxNum);

    // timing
    clock_t start, end;
    start = clock();

    int counter = 0;
    for (int i = 1; i <= maxNum; i++)
    {
        int isPrime = prime(i, find_divisor(i));
        if (isPrime == 1)
        {
            primes[counter] = i;
            counter++;
        }
    }

    for (int i = 0;; i++)
    {
        if (primes[i] == 0 || primes[i] == '\0')
        {
            break;
        }
        printf("%d: %d\n", i, primes[i]);
    }
    end = clock();

    printf("\nTime: %lf \n", (double)(end - start) / CLOCKS_PER_SEC);
}
