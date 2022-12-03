#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE '-'

void board_print(int *board[BOARD_SIZE]);
char convert_player(int player);
void init_board(int *board[BOARD_SIZE]);
bool winner(int *board[BOARD_SIZE]);
bool legal_move(int *board[BOARD_SIZE], int *move);
void make_move(int *board[BOARD_SIZE], int *move);

int main(void){
    int player = 1;
    int board[BOARD_SIZE][BOARD_SIZE];

    init_board(board);
}

void init_board(int *board[BOARD_SIZE]){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = 0;
        }
    }
}

char convert_player(int player){
    if (player == 1) return 'X';
    if (player == -1) return 'O';
    return EMPTY_SPACE;
}

void board_print(int *board[BOARD_SIZE]){
    char player_1 = 'X';
    char player_2 = 'O';

    for (int i = 0; i < BOARD_SIZE; i++){
        printf("|\t");
        for (int j = 0; j < BOARD_SIZE; j++){
            printf("%c\t|", convert_player(board[i][j]));
        }
        printf("-----------");
    }
}
