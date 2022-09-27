#include <stdlib.h>
#include <stdio.h>
#define MAX 1000
#define MIN -1000

void drawBoard(char positions[3][3]);
int legalMove(char *board, int *move);
void getMove(int *PtrRow, int *PtrCol);
char whichPlayer(int currentPlayer);
void makeMove(char *board, int *move, int currenPlayer);
int checkGameOver(char *board);
int miniMax(char *board, int currentPlayer);
void bestMove(char *board, int currentPlayer, int *ptrRow, int *ptrCol);


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

void getMove(int *PtrRow, int *PtrCol)
{
    printf("\nChoose row: \n");
    scanf("%d", &*PtrRow);
    printf("\nChose column: \n");
    scanf("%d", &*PtrCol);
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

void makeMove(char *board, int *move, int currenPlayer)
{
    board[move[0] * 3 + move[1]] = whichPlayer(currenPlayer);
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

        // horizontal check
        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != '_')
        {
            return 1;
        }

        // vertical check
        else if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != '_')
        {
            return 1;
        }
    }
    if (freeSpaces <= 0)
    {
        return 2;
    }

    // diagonal check
    else if (board[0] == board[4] && board[4] == board[8] && board[4] != '_')
    {
        return 1;
    }

    else if (board[2] == board[4] && board[4] == board[6] && board[4] != '_')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int miniMax(char *board, int currentPlayer)
{
    // returns positive if maximizing won and negative if minimizing won
    if (checkGameOver((board) != 0)
    {
        if (currentPlayer == 1)
        {
            if (checkGameOver(board) == 1)
            {
                return MAX;
            }
            else if (checkGameOver(board) == 2)
            {
                return 0;
            }
        }
        else if (currentPlayer == -1)
        {
            if (checkGameOver(board) == 1)
            {
                return MIN;
            }
            else if (checkGameOver(board) == 2)
            {
                return 0;
            }
        }
    }

    if (currentPlayer == 1)
    {
        int bestScore = MIN;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; i < 3; ++j)
            {
                board[i * 3 + j] = whichPlayer(currentPlayer);
                int getEval = miniMax(board, currentPlayer * -1);
                if (getEval > bestScore)
                {
                    bestScore = getEval;
                }
            }
        }
        return bestScore;
    }
    else if (currentPlayer == -1)
    {
        int bestScore = MAX;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; i < 3; ++j)
            {
                board[i * 3 + j] = whichPlayer(currentPlayer);
                int getEval = miniMax(board, currentPlayer * -1);
                if (getEval < bestScore)
                {
                    bestScore = getEval;
                }
            }
        }
        return bestScore;
    }
    else return 0;
}

void bestMove(char *board, int currentPlayer, int *ptrRow, int *ptrCol)
{
    int bestMove[2] = {-1};
    int negativeNumber = MIN;

    // checks all possible combinations of moves
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; i < 3; ++j)
        {
            board[i * 3 + j] = whichPlayer(currentPlayer);
            int getEval = miniMax(board, currentPlayer * -1);
            if (getEval > negativeNumber)
            {
                negativeNumber = getEval;
                bestMove[0] = i;
                bestMove[1] = j;
            }
        }
    }
    *ptrRow = bestMove[0];
    *ptrCol = bestMove[1];
}

int main()
{
    printf("\n");
    printf("A");
    // init board
    char board[3][3] = {{'_', '_', '_'},
                        {'_', '_', '_'},
                        {'_', '_', '_'}};
    int currentPlayer = 1; // 1 == x, -1 == O;
    int gameStillGoing = 1;

    // game loop
    while (gameStillGoing == 1)
    {
        // init
        int moveFound = 0;

        // copy of board
        char copyBoard[3][3] = {{'_'}, {'_'}, {'_'}};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                copyBoard[i][j] = board[i][j];
            }
        }

        // draws board
        drawBoard(board);
        // debug: printf("\ncheckGameOver return: %d\n", checkGameOver((char *)board));

        // Checks if winner
        if (checkGameOver((char *)board) == 1)
        {
            gameStillGoing = 0;
            break;
        }
        // check for tie
        else if (checkGameOver((char *)board) == 2)
        {
            gameStillGoing = 2;
            break;
        }

        // make move, player
        if (currentPlayer == -1)
        {
            while (moveFound == 0)
            {
                int tempPlaceHolder[2] = {-1};
                getMove(&tempPlaceHolder[0], &tempPlaceHolder[1]);

                if (legalMove((char *)board, tempPlaceHolder) == 1)
                {
                    makeMove((char *)board, tempPlaceHolder, currentPlayer);
                    currentPlayer = currentPlayer * -1;
                    moveFound = 1;
                }
            }
        }

        // computer move
        else if (currentPlayer == 1)
        {
            printf("A");
            int temp[2] = {0, 0};
            bestMove((char *)copyBoard, currentPlayer, &temp[0], &temp[1]);
            printf("B");
            makeMove((char *)board, temp, currentPlayer);
            currentPlayer = currentPlayer * -1;
        }
    }
}
