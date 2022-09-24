#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int miniMax(int sticks, int currentPlayer)
{
    if (sticks <= 0)
    {
        return 1000 * -currentPlayer;
    }
    if (currentPlayer == 1)
    {
        int bestScore = -1000;
        int bestMove = -1;
        for (int i = 1; i <= 2; i++)
        {
            int getEval = miniMax(sticks - i, currentPlayer * -1);
            if (getEval > bestMove)
            {
                bestScore = getEval;
                bestMove = i;
            }
        }
        return bestScore;
    }
    else if (currentPlayer == -1)
    {
        int bestScore = 1000;
        int bestMove = -1;
        for (int i = 1; i <= 2; i++)
        {
            int getEval = miniMax(sticks - i, currentPlayer * -1);
            if (getEval < bestMove)
            {
                bestScore = getEval;
                bestMove = i;
            }
        }
        return bestScore;
    }
    else
    {
        return -1;
    }
}

int bestMove(int sticks, int currentPlayer)
{
    int bestMove = -1;
    int negativeNumber = -1000;

    // ai player
    for (int i = 1; i <= 2; i++)
    {
        int getEval = miniMax(sticks - i, currentPlayer * -1);
        if (getEval > negativeNumber)
        {
            negativeNumber = getEval;
            bestMove = i;
        }
    }
    return bestMove;
}

int callFunc(int sticks)
{
    int removeAmt = bestMove(sticks, 1);
    return removeAmt;
}

int game(int sticks, int currentPlayer)
{
    while (sticks > 0)
    {
        if (currentPlayer == -1)
        {
            int remove = (rand() % 2) + 1;
            sticks = sticks - remove;
            currentPlayer = currentPlayer * -1;
        }

        else
        {
            int remove = callFunc(sticks);
            sticks = sticks - remove;
            currentPlayer = currentPlayer * -1;
        }
    }
    if (currentPlayer == 1)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    srand(time(NULL));
    int winnerRandom = 0;
    int winnerAi = 0;
    const int sticks = 11;
    const int player = 1;

    for (int i = 0; i < 10000; i++)
    {
        if (game(sticks, player) == 1)
        {
            winnerAi++;
        }
        else
        {
            winnerRandom++;
        }
    }

    printf("\nRandom player: %d \nAi: %d\n", winnerRandom, winnerAi);
}
