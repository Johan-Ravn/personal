
#ifndef MINI_MAX_TIC_TAC_TOE_H
#define MINI_MAX_TIC_TAC_TOE_H

#include <stdio.h>
#include <stdlib.h>
#define MIN -1000
#define MAX 1000

void drawBoard(char *board);
char whichPlayer(int player);
int moveLegal(char *board, int *move);
void makeMove(char *board, int *move, int player);
int gameState(char *board);
int miniMaxFunc(char *board, int player);
void bestMove(char *board, int player, int *ptrRow, int *ptrCol);


#endif
