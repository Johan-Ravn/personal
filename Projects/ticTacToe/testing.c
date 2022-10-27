#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// tictactoe game
int main()
{
    // 0 = empty, 1 = X, 2 = O
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int player = 1;
    int move[2];
    int winner = 0;
    int gameover = 0;
    int i, j;

    // game loop
    while (gameover == 0)
    {
        // print board
        printf(" %d | %d | %d \n", board[0], board[1], board[2]);
        printf("---+---+---\n");
        printf(" %d | %d | %d \n", board[3], board[4], board[5]);
        printf("---+---+---\n");
        printf(" %d | %d | %d \n", board[6], board[7], board[8]);

        // get move
        printf("Player %d, enter your move: ", player);
        scanf("%d %d", &move[0], &move[1]);

        // check if move is legal
        if (board[move[0] * 3 + move[1]] == 0)
        {
            // make move
            board[move[0] * 3 + move[1]] = player;
        }
        else
        {
            printf("Illegal move, try again");
            continue;
        }

        // check for winner
        for (i = 0; i < 3; ++i)
        {
            if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != 0)
            {
                winner = player;
                gameover = 1;
            }
            if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != 0)
            {
                winner = player;
                gameover = 1;
            }
        }
}
