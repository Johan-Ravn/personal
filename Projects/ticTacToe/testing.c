#include <stdio.h>

int gameState(char *board)
{
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

    char arr[9] = {'X', 'X', 'X',
                  '_', '_', '_',
                  '_', '_', '_'};
    printf("Game state: %d\n", gameState(arr));

    return 0;
}
