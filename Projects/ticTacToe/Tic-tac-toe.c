#include "Tic-tac-toe.h"

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
        return 1;
    }

    // horizontal check
    for (int i = 0; i < 3; ++i)
    {
        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != '_')
        
        {
            return 1;
        }
    }
    
    // vertical check
    for (int i = 0; i < 3; ++i)
    {
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != '_')
        {
            return 1;
        }
    }

    // diagonal check
    if (board[0] == board[4] && board[4] == board[8] && board[4] != '_')
    {
        return 1;
    }

    else if (board[2] == board[4] && board[4] == board[6] && board[4] != '_')
    {
        return 1;
    }

    return 0;
}

int* getMove()
{
    int move[2] = {0};

    printf("\nChoose row: \n");
    scanf("%d", &move[0]);
    printf("\nChose column: \n");
    scanf("%d", &move[1]);

    return move;
}

void makeMove(char* board, int* move, int currenPlayer)
{
    board[move[0] * 3 + move[1]] = whichPlayer(currenPlayer);
}

int main()
{
    printf("\n");
    // init board
    char board[3][3] = {{'_', '_', '_'},
                        {'_', '_', '_'},
                        {'_', '_', '_'}};
    int currentPlayer = 1; // 1 == x, -1 == O;
    int gameStillGoing = 1;

    // intro
    printf("\nWelcome to Tic Tac Toe\n");

    while (gameStillGoing == 1)
    {
        // init
        int moveFound = 0;

        // drawboard
        drawBoard(board);
        // debug: printf("\ncheckGameOver return: %d\n", checkGameOver((char *)board));

        // Checks if winner
        if (checkGameOver((char *) board) == 1)
        {
            gameStillGoing = 0;
            break;
        }
        // check for tie
        else if (checkGameOver((char *) board) == 2)
        {
            gameStillGoing = 2;
            break;
        }

        // make move
        while (moveFound == 0)
        {
            int tempPlaceHolder[2] = {-1};
            int *move = getMove();
            tempPlaceHolder[0] = *move;
            tempPlaceHolder[1] = *(move + 1);

            if (legalMove((char *) board, tempPlaceHolder) == 1)
            {
                makeMove((char*) board, tempPlaceHolder, currentPlayer);
                currentPlayer = currentPlayer * -1;
                moveFound = 1;
            }

        }
    }
    printf("\nGame is over\n");

    if (gameStillGoing == 2)
    {
        printf("It's a tie");
    }

    printf("\n Player %c won", whichPlayer(currentPlayer * -1));

    return 0;
}
