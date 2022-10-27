#include <stdio.h>
#include <stdlib.h>

void makeMove(int player, int *ptrBoard, int move);
int checkWin(int *board);
int getMove();
int moveLegal(int move, int *board);
void gravity(int *ptrBoard, int move);
void printBoard(int *board);

// check if any 4 index in row, column, diagonal is the same thing
int checkWin(int *board)
{
    // Column
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int n = 0; n < 3; n++)
            {
                if (board[(n + j) + (i * 7)] == board[(1 + n + j) + (i * 7)] && board[(n + j) + (i * 7)] != 0)
                {
                    if (n == 3)
                    {
                        printf("AAAAA");
                        return 1;
                    }
                }
                else
                    break;
            }
        }
    }

    return 0;
}
void printBoard(int *board)
{
    for (int i = 0; i < 6; i++)
    {
        printf("%d  | %d  | %d  | %d  | %d  | %d  | %d\n", board[0 + (i * 7)], board[1 + (i * 7)], board[2 + (i * 7)], board[3 + (i * 7)], board[4 + (i * 7)], board[5 + (i * 7)], board[6 + (i * 7)]);
        printf("_________________________\n");
    }
}

int moveLegal(int move, int *board)
{
    int boardPos = board[move];
    if (boardPos == 0)
        return 1;
    else
        return 0;
}

int getMove(int *board)
{
    while (1)
    {
        int move = 9;
        printf("What move do you wanna make?\n");
        scanf("%d", &move);
        if (move >= 0 && move < 7 && moveLegal(move, board))
        {
            return move;
        }
    }
}

void gravity(int *ptrBoard, int move)
{
    int currentFile = move;
    while (currentFile <= 34)
    {
        if (ptrBoard[currentFile + 7] == 0)
        {
            ptrBoard[currentFile + 7] = ptrBoard[currentFile];
            ptrBoard[currentFile] = 0;
            currentFile += 7;
        }
        else
            break;
    }
}

void makeMove(int player, int *ptrBoard, int move)
{
    ptrBoard[move] = player;
}

int main()
{
    int board[42] = {0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 1, 1, 1};
    int winner = 0;
    int player = 1;

    while (1)
    {
        printBoard(board);
        if (checkWin(board) != 0)
        {
            winner = checkWin(board);
            break;
        }
        int move = getMove(board);
        makeMove(player, board, move);
        gravity(board, move);
        player *= -1;
    }

    return 0;
}
