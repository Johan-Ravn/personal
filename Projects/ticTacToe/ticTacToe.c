// to do: fix it

#include <stdlib.h>
#include <stdio.h>

void drawBoard(int positions[3][3])
{
    printf("_________");
    for (int i = 0; i < 3; i++)
    {
        printf("\n%c | %c | %c\n", positions[i][0], positions[i][1], positions[i][2]);
        printf("_________");
    }
}

char whichPlayer(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        return 'X';
    }
    else 
    {
        return 'O';
    }
}

int makeMove(int positions[3][3], int move[2], int turn)
{
    positions[move[0]][move[1]] = whichPlayer(turn);
    return positions[3][3];
}

int checkIfPosEmpty(int positions[3][3], int move[2], int turn)
{
    if (positions[move[0]][1] == '_')
    {
        return makeMove(positions, move, turn);
    }
    else 
    {
        return 0;
    }
}


int main()
{
    printf("\n");
    // init board
    int board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int currentPlayer = 1; // 1 == x, -1 == O;
    int move[2] = {1, 1};

    // intro
    printf("\nWelcome to Tic Tac Toe\n");
    drawBoard(board);
    printf("Player %c", whichPlayer(currentPlayer));

    board[3][3] = checkIfPosEmpty(board[3][3], move[2], currentPlayer);
    printf("\nBoard:\n%d", board[3][3]);

    return 0;
}
