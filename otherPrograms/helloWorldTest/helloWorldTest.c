#include <stdio.h>

int main(void){
    int i = 1;
    while(i <= 10){
        if (i == 1){
            printf("First comes: %d \n", i);
            ++i;
        }
        else if(1 < i && i < 10){
            printf("Then comes: %d \n", i);
            ++i;
        }
        else{
            printf("At last comes: %d", i);
            ++i;
        }
    }
    printf("\n \n");
    return 0;
}