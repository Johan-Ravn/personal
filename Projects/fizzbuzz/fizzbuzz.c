#include "fizzbuzz.h"

const char *enum_mapping(int enum_num) {
    switch (enum_num){
    case 0:
        return "fizz";
    case 1:
        return "buzz";

    default:
        exit(EXIT_FAILURE);
    }
}

const char *fizzBuzz(int num) {
    enum words{
        FIZZ,
        BUZZ,
    };

    char *return_value = malloc(100 * sizeof(char));

    if (num % 3 == 0){
        strcat(return_value, enum_mapping(FIZZ));
    }
    if (num % 5 == 0){
        strcat(return_value, enum_mapping(BUZZ));
    }

    return return_value;
}

int main(void){
    int maxCount = 10000;

    for (int i = 1; i <= maxCount; i++){
        const char *word = fizzBuzz(i);
        if (strcmp(word, "") == 0){
            printf("%d: %d\n", i, i);
        }
        else{
            printf("%d: %s\n", i, word);
        }
    }
}
