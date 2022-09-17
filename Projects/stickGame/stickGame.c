
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("\nWelcome to the sticks game \n");
    int sticks = 11;
    int currentPlayer = 1; // currentPlayer 1 == 1 and currentPlayer 2 == 2
    const int player1 = 1;
    const int player2 = 2;

    while (sticks > 0)
    {
        printf("\nThere is %d sticks left", sticks);

        for (int i = 1; i != 0;)
        {
            int remove = 0;

            printf("\nIt's Player %d turn to remove\nChoose an integer 1 or 2\n", currentPlayer);
            scanf("%d", &remove);

            if (remove == 1 || remove == 2)
            {
                sticks = sticks - remove;
                if (currentPlayer == player1)
                {
                    currentPlayer = player2;
                }
                else
                {
                    currentPlayer = player1;
                }
                i = 0;
            }
            else
            {
                printf("Invalid input");
            }
        }
    }

    if (currentPlayer == player1)
    {
        printf("\nCongratulations player 2 for winning the stick game");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("\nCongratulations player 1 for winning the sticks game");
        exit(EXIT_SUCCESS);
    }
}
