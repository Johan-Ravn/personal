
#include <stdlib.h>
#include <stdio.h>

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

int main()
{
    printf("\nWelcome to the sticks game \n");
    int sticks = 11;
    int currentPlayer = 1; // Computer 1 == 1 and currentPlayer 2 == -1

    while (sticks > 0)
    {
        printf("\n\nThere is %d sticks left", sticks);

        if (currentPlayer == -1)
        {
            for (int i = 1; i != 0;)
            {
                int remove = 0;

                printf("\nIt's Player's turn to remove\nChoose an integer 1 or 2\n");
                scanf("%d", &remove);

                if (remove == 1 || remove == 2)
                {
                    sticks = sticks - remove;
                    currentPlayer = currentPlayer * -1;
                    i = 0;
                }
                else
                {
                    printf("Invalid input");
                }
            }
        }

        else
        {
            int remove = callFunc(sticks);
            sticks = sticks - remove;
            printf("\nIt's is the computer turn to move\nThe computer removed %d sticks", remove);
            currentPlayer = currentPlayer * -1;
        }
    }

    if (currentPlayer == 1)
    {
        printf("\nCongratulations player for winning the stick game");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("\n\nThe computer won the stick game");
        exit(EXIT_SUCCESS);
    }
}
