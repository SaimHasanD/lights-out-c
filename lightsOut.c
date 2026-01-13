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

    if (row >= SIZE || col >= SIZE || row < 0 || col < 0)
        printf("Enter a correct value");

    else
        {
            grid[row][col] = 1 - grid[row][col];
            // up
            if (row > 0)
                grid[row - 1][col] = 1 - grid[row - 1][col];

            // down
            if (row < SIZE - 1)
                grid[row + 1][col] = 1 - grid[row + 1][col];

            // left
            if (col > 0)
                grid[row][col - 1] = 1 - grid[row][col - 1];

            // right
            if (col < SIZE - 1)
                grid[row][col + 1] = 1 - grid[row][col + 1];
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
