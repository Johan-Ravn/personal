#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define MIN -1000

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

int moveLegal(char *board, int *move)
{
    if (board[move[0] * 3 + move[1]] == '_')
    {
        return 1;
    }
    return 0;
}

void makeMove(char *board, int *move, int player)
{
    board[move[0] * 3 + move[1]] = whichPlayer(player);
}

int freeSpace(char *board)
{
    int freeSpace = 9;
    for (int i = 0; i < 8; ++i)
    {
        if (board[i] != '_')
        {
            --freeSpace;
        }
    }
    return freeSpace;
}

int gameState(char *board)
{
    freeSpace(board);

    // Vertical and horizontal checks
    for (int i = 0; i < 3; ++i)
    {
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

int miniMax(char *board, int player)
{
    int game = gameState(board);
    if (game != 0)
    {
        if (game == 1)
        {
            if (whichPlayer(-1 * (player)) == 'O')
            {
                return MIN;
            }
            else if (whichPlayer(-1 * (player)) == 'X')
            {
                return MAX;
            }
        }
        else if (game == 2)
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
            if (board[i] == '_')
            {
                board[i] = whichPlayer(player);
                int score = miniMax(board, -1 * player);
                board[i] = '_';
                if (score >= bestScore)
                {
                    bestScore = score;
                }
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
            if (board[i] == '_')
            {
                board[i] = whichPlayer(player);
                int score = miniMax(board, -1 * player);
                board[i] = '_';
                if (score <= bestScore)
                {
                    bestScore = score;
                }
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
        if (board[i] == '_')
        {
            board[i] = whichPlayer(player);
            int evalPos = miniMax(board, -1 * player);
            board[i] = '_';
            if (evalPos >= minEval)
            {
                minEval = evalPos;
                iterationBestMove = i;
            }
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
    // init
    char board[9] = {'_', '_', '_',
                     '_', '_', '_',
                     '_', '_', '_'};
    int player = 1;      // 1 = X, -1 = O
    int gameOngoing = 1; // 1 = game still underway, 2 == tie, 0 == winner been found

    // start of game
    printf("\nWelcome to ticTacToe\n");

    while (gameOngoing == 1)
    {
        // placeHolder
        int move[2] = {0, 0};

        drawBoard(board);
        // checks if game is over
        int gameS = gameState(board);
        if (gameS != 0)
        {
            gameOngoing = gameState(board);
            break;
        }
        printf("\nIt's %c turn to make a move\n", whichPlayer(player));

        // human move - works
        if (player == -1)
        {
            while (1)
            {
                printf("\nMake a move\n");
                scanf("%d", &move[0]);
                scanf("%d", &move[1]);

                // input val
                if (move[0] >= 0 && move[0] <= 3 && move[1] >= 0 && move[1] <= 3)
                {
                    int isMoveLegal = moveLegal(board, move);
                    if (isMoveLegal == 1)
                    {
                        makeMove(board, move, player);
                        player = player * -1;
                        break;
                    }
                }
                else
                {
                    printf("Not valid input\n");
                }
            }
        }

        // computer move
        else if (player == 1)
        {
            int temp[2] = {0, 0};
            bestMove(board, player, &move[0], &move[1]);
            makeMove(board, move, player);
            player = player * -1;
        }
    }

    printf("Game is over: \n");
}
