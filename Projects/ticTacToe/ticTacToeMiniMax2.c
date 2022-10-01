#include <stdlib.h>
#include <stdio.h>
#define MAX 1000
#define MIN -1000

// Draws the board
void drawBoard(char *positions)
{
    printf("_________");
    for (int i = 0; i < 3; i++)
    {
        printf("\n%c | %c | %c\n", positions[0 + (i * 3)], positions[1 + (i * 3)], positions[2 + (i * 3)]);
        printf("_________");
    }
}

void getMove(int *PtrRow, int *PtrCol)
{
    int move[2] = {0, 0};

    printf("\nChoose row: \n");
    scanf("%d", &move[0]);
    printf("\nChose column: \n");
    scanf("%d", &move[1]);

    *PtrRow = move[0];
    *PtrCol = move[1];
}

char whichPlayer(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        return 'X';
    }
    else
        return 'O';
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

void makeMove(char *board, int *move, int currenPlayer)
{
    board[move[0] * 3 + move[1]] = whichPlayer(currenPlayer);
}

int checkGameOver(char *board)
{
    // check for no available spaces
    int freeSpaces = 9;
    for (int i = 0; i < 8; ++i)
    {
        if (board[i] != '_')
        {
            --freeSpaces;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        // horizontal check
        if (board[0 + (i * 3)] == board[1 + (i * 3)] && board[1 + (i * 3)] == board[2 + (i * 3)] && board[0 + (i * 3)] != '_')
        {
            return 1;
        }

        // vertical check
        else if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i] && board[0 + i] != '_')
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

int miniMax(char *board, int player)
{
    if (checkGameOver(board) != 0)
    {
        printf("F");
        if (checkGameOver(board) == 1)
        {
            if (whichPlayer(-1 * (player)) == 1)
            {
                return MIN;
            }
            else if (whichPlayer(-1 * (player)) == -1)
            {
                return MAX;
            }
        }
        else if (checkGameOver(board) == 2)
        {
            return 0;
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }

    // maximizing player
    else if (player == 1)
    {
        int bestScore = MIN;

        for (int i = 0; i < 9; ++i)
        {
            board[i] = whichPlayer(player);
            int score = miniMax(board, -1 * player);
            board[i] = '_';
            if (score >= bestScore)
            {
                bestScore = score;
            }
        }
        return bestScore;
    }

    // minimizing player
    else if (player == -1)
    {
        int bestScore = MAX;

        for (int i = 0; i < 9; ++i)
        {

            board[i] = whichPlayer(player);
            int score = miniMax(board, -1 * player);
            board[i] = '_';
            if (score <= bestScore)
            {
                bestScore = score;
            }
        }
        return bestScore;
    }
    else
        exit(EXIT_FAILURE);
    return 0;
}

void bestMove(char *board, int player, int *ptrRow, int *ptrCol)
{
    int bestMove[2] = {0, 0};
    int iterationBestMove = 0;
    int minEval = MIN;

    // code. Runs through all possible moves, and returns the best move
    for (int i = 0; i < 9; ++i)
    {
        board[i] = whichPlayer(player);
        int evalPos = miniMax(board, -1 * player);
        if (evalPos >= minEval)
        {
            minEval = evalPos;
            iterationBestMove = i;
        }
    }

    // finds the row and col of the iteration
    bestMove[0] = iterationBestMove / 3;
    bestMove[1] = iterationBestMove % 3;

    // pointer to address of array in main func
    *ptrRow = bestMove[0];
    *ptrCol = bestMove[1];
}

int main()
{
    char board[] = {'_', '_', '_',
                    '_', '_', '_',
                    '_', '_', '_'};
    // init, board
    int currentPlayer = 1; // 1 == x, -1 == O;
    int gameStillGoing = 1;

    // copy of board
    char copyBoard[9] = {'_'};
    for (int i = 0; i < 9; ++i)
    {
        copyBoard[i] = board[i];
    }

    // pointers
    char *ptrBoard[] = &board;
    char ptrCopyBoard[] = &copyBoard;

    // game loop
    while (gameStillGoing == 1)
    {
        // draws board
        drawBoard(board);

        // Checks if winner, (char *) because we are passing a multidimensional array
        if (checkGameOver(board) == 1)
        {
            gameStillGoing = 0;
            break;
        }
        // check for tie
        else if (checkGameOver(board) == 2)
        {
            gameStillGoing = 2;
            break;
        }

        // make move, player = O
        if (currentPlayer == -1)
        {
            while (1)
            {
                int move[2] = {-1};
                getMove(&move[0], &move[1]);

                if (legalMove(board, move) == 1)
                {
                    makeMove(board, move, currentPlayer);
                    currentPlayer = currentPlayer * -1;
                    break;
                }
            }
        }

        // computer move
        else if (currentPlayer == 1)
        {
            printf("A");
            int move[2] = {-1};
            bestMove(copyBoard, currentPlayer, &move[0], &move[1]);
            printf("B");
            makeMove(board, move, currentPlayer);
            printf("C");
            currentPlayer = currentPlayer * -1;
        }
    }
}
