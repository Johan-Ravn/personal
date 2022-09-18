// to do: fix it

#include <stdlib.h>
#include <stdio.h>

void drawBoard(char positions[3][3])
{
    printf("_________");
    for (int i = 0; i < 3; i++)
    {
        printf("\n%c | %c | %c\n", positions[i][0], positions[i][1], positions[i][2]);
        printf("_________");
    }
}

int checkForWinner(char positions[3][3])
{
    // check if no available spaces
    int gameOver = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (positions[i][j] == '_')
            {
                gameOver = 0;
            }
        }
    }
    if (gameOver == 1)
    {
        return 1;
    }

    // checking vertical
    for (int i = 0; i < 3; i++)
    {
        if (positions[i][0] == positions[i][1] == positions[i][2] && positions[i][0] != '_')
        {
            return 1;
        }
    }

    // Checking for horizontal
    for (int i = 0; i < 3; i++)
    {
        if (positions[0][i] == positions[1][i] == positions[2][i] && positions[0][i] != '_')
        {
            return 1;
        }
    }
    // Checking for diagonals
    if (positions[0][0] == positions[1][1] == positions[2][2] && positions[1][1] != '_')
    {
        return 1;
    }
    else if (positions[0][2] == positions[1][1] == positions[2][0] && positions[1][1] != '_')
    {
        return 1;
    }
    else // if none of the above, game still going
    {
        return 0;
    }
}

char whichPlayer(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        return 'X';
    }
    else if (currentPlayer == -1)
    {
        return 'O';
    }
    else
    {
        return '_';
    }
}

int checkForLegalMove(char pos)
{
    if (pos != '_')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int makeMove(char positions[3][3], int move[2])
{
    if (checkForLegalMove(positions[move[0]][move[1]]) != 0)
    {
        return 1;
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
    char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int currentPlayer = 1; // 1 == x, -1 == O;
    int gameStillGoing = 1;

    // intro
    printf("\nWelcome to Tic Tac Toe\n");

    while (gameStillGoing == 1)
    {
        int col, row = 0;
        int move[2] = {0, 0};

        int legalMoveTrue = 0;

        drawBoard(board);
        printf("Player %c\n", whichPlayer(currentPlayer));

        while (legalMoveTrue == 0)
        {
            printf("\nPlayer %c what move do you wanna make: \n", whichPlayer(currentPlayer));
            scanf("%d%d", &move[0], &move[1]);
            if (makeMove(board[3][3], &move[2]) == 1)
            {
                board[move[0]][move[1]] = whichPlayer(currentPlayer);
                legalMoveTrue = 1;
            }
        }
        if (checkForWinner(board[3][3]) == 1)
        {
            gameStillGoing = 0;
        }
    }

    return 0;
}
