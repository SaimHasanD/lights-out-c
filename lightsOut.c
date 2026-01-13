#include <stdio.h>

#define SIZE 5

int main()
{
    int grid[SIZE][SIZE];

    for (int i=0; i<SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
            grid[i][j] = 0;
    }

    for (int i=0; i<SIZE; i++)
    {
        printf("\n");
        for(int j=0; j < SIZE; j++)
            if (grid[i][j] == 0)
            printf(". ");
        else
            printf("* ");

    }

    printf("\nLights Out Game\n");
    return 0;
}
