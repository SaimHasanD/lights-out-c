#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int moves = 0;

void printGrid(int grid[SIZE][SIZE])
{
    printf("    ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);

    printf("\n   -----------\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
                printf(". ");
            else
                printf("* ");
        }
        printf("\n");
    }
}

void toggle(int grid[SIZE][SIZE], int row, int col)
{
    // center
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

    moves ++;
}

void randomizeGrid(int grid[SIZE][SIZE],int difficulty)
{
    for (int k = 0; k < 2 * difficulty; k++)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        toggle(grid, row, col);
        moves = 0;
    }
}

int checkWin(int grid[SIZE][SIZE])
{
    int won = 1;
    for (int i=0; i<SIZE; i++)
    {
        for(int j=0; j < SIZE; j++)
        {
            if(grid[i][j] == 1) won = 0;
        }
    }
    return won;
}

int main()
{

    int grid[SIZE][SIZE];
    int row, col, difficulty;


    // initialize grid
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = 0;

    // Select difficulty
    printf("\nSelect Difficulty Level:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &difficulty);

    // default to medium
    if (difficulty < 1 || difficulty > 3)
    difficulty = 2;

    srand(time(NULL));

    // create easy puzzle
    randomizeGrid(grid, difficulty);

    while (1)
    {
        printGrid(grid);

        printf("\nEnter a row and column (0-4) or -1 -1 to quit: ");
        scanf("%d %d", &row, &col);

        if (row == -1 && col == -1)
        {
            printf("Game ended.\n");
            break;
        }

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        {
            printf("Invalid input!\n");
            continue;
        }

        toggle(grid, row, col);

        if (checkWin(grid))
        {
            printGrid(grid);
            printf("\n\nYou win in %d moves!\n", moves);
            break;
        }
    }

    return 0;
}
