
#ifndef MINIPROJECTS_TIC_TAC_TOE_H
#define MINIPROJECTS_TIC_TAC_TOE_H

#include <stdio.h>

void drawBoard(char positions[3][3]);
int legalMove(char *board, int *move);
char whichPlayer(int currentPlayer);
int checkGameOver(char *board);
int* getMove();
void makeMove(char* board, int* move, int currenPlayer);

#endif //MINIPROJECTS_TIC_TAC_TOE_H
