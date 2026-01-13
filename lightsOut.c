#include <stdio.h>

#define SIZE 5

int main()
{
    int grid[SIZE][SIZE];

    int row, col;

    for (int i=0; i<SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
            grid[i][j] = 0;
    }

    printf("Enter a row and column: ");
    scanf("%d %d", &row,&col);

    if (grid[row][col] == 0)
                grid[row][col] = 1;
            else
                grid[row][col] = 0;


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
