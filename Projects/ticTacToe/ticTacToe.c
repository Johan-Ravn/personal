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

int legalMove(char *board, int *move)
{
    if (board[move[0] * 3 + move[1]] == '_')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char whichPlayer(char currentPlayer)
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

int checkGameOver(char *board)
{
    // Check for no available spaces
    int freeSpaces = 9;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i * 3 + j] != '_')
            {
                --freeSpaces;
            }
        }
    }
    if (freeSpaces <= 0)
    {
        return 0;
    }

    // Checks verticals
    for (int i = 0; i < 3; ++i)
    {
        if (board[i * 3] == board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != '_')
        {
            return 0;
        }
    }
    // Checks horizontals
    for (int i = 0; i < 3; ++i)
    {
        if (board[i * 3] == board[(1 + i) * 3 + ])
        {
            return 0;
        }
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
        int moveNotFound = 1;
        int move[2] = {0};

        drawBoard(board);

        // Checks if game is over
        if (checkGameOver((char *)board) == 0)
        {
            gameStillGoing = 0;
            break;
        }

        while (moveNotFound == 1)
        {
            for (int i = 0; i < 3; ++i)
            {
                if (moveNotFound == 0)
                {
                    break;
                }
                for (int j = 0; j < 3; j++)
                {
                    int tryMove[2] = {i, j};
                    if (legalMove((char *)board, tryMove) == 1)
                    {
                        move[0] = i;
                        move[1] = j;
                        moveNotFound = 0;
                        break;
                    }
                }
            }
        }
        board[move[0]][move[1]] = whichPlayer(currentPlayer);
        currentPlayer = currentPlayer * -1;
    }
    printf("Game is over");

    return 0;
}
