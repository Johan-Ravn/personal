#include <stdio.h>
#include <stdlib.h>

// works
void drawBoard(char *board)
{
    printf("_________");
    for (int i = 0; i < 3; i++)
    {
        printf("\n%c | %c | %c\n", board[0 + (i * 3)], board[1 + (i * 3)], board[2 + (i * 3)]);
        printf("_________");
    }
}

// works
char whichPlayer(int player)
{
    char rVal = 'Z';
    rVal = (player == 1) ? 'X' : 'O';
    return rVal;
}

int moveLegal(int *move, char *board)
{
    if (board[move[0] * 3 + move[1]] == '_')
    {
        return 1;
    }
    return 0;
}

void makeMove(int *move, char *board, int player)
{
    board[move[0] * 3 + move[1]] = whichPlayer(player);
}

int gameState(char *board)
{
    printf("A");
    // Check for tie
    int freeSpace = 9;
    for (int i = 0; i < 8; ++i)
    {
        if (board[i] != '_')
        {
            --freeSpace;
        }
    }

    // Vertical and horizontal checks
    for (int i = 0; i < 3; ++i)
    {
        printf("A");
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != '_')
        {
            return 1;
        }

        else if (board[0 + (i * 3)] == board[1 + (i * 3)] && board[1 + (i * 3)] == board[2 + (i * 3)] && board[0 + (i * 3)] != '_')
        {
            return 1;
        }
    }

    // diagonal checks
    if (board[0] == board[4] && board[4] == board[8] && board[4] != '_')
    {
        return 1;
    }

    else if (board[2] == board[4] && board[4] == board[6] && board[4] != '_')
    {
        return 1;
    }

    // tie
    if (freeSpace <= 0)
    {
        return 2; // tie
    }

    // Game still going
    return 0;
}

int main()
{
    // init
    char board[9] = {'X', 'X', 'X',
                     '_', '_', '_',
                     '_', '_', '_'};
    int player = -1;     // 1 = X, -1 = O
    int gameOngoing = 1; // 1 = game still underway, 2 == tie, 0 == winner been found

    // start of game
    printf("\nWelcome to ticTacToe\n");

    while (gameOngoing == 1)
    {
        // placeHolder
        int move[2] = {0, 0};

        // checks if game is over
        printf("A");
        if (gameState(board) != 0)
        {
            printf("B");
            gameOngoing = gameState(board);
        }

        // start off every move
        drawBoard(board);
        printf("\nIt's %c turn to make a move\n", whichPlayer(player));

        // human move - works
        if (player == -1)
        {
            while (1)
            {
                printf("\nMake a move\n");
                scanf("%d", &move[0]);
                scanf("%d", &move[1]);
                if (moveLegal(move, board) == 1)
                {
                    makeMove(move, board, player);
                    player = player * -1;
                    break;
                }
            }
        }

        // computer move
        else if (player == 1)
        {
        }
    }
}
