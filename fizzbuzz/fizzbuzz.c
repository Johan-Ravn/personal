#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *fizzBuzz(int num){
    if ((num % 3 == 0) && (num % 5 == 0)){
        return "fizzbuzz";
    }
    else if(num % 3 == 0){
        return "fizz";
    }
    else if (num % 5 == 0){
        return "buzz";
    }
    return "";
}


int main(void){
    int num = 100;

    for (int i = 1; i <= 100; i++){
        char *word = (char*)(malloc(100));
        strcpy(word, fizzBuzz(i));
        if (strcmp(word, "") == 0){
            printf("%d: %d\n", i, i);
        }
        else{
            printf("%d: %s\n", i, word);
        }
        free(word);
    }
    
}
