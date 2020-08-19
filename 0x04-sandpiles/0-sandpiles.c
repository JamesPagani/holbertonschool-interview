#include "sandpiles.h"

/**
 * stability_check - Checks the stability of a sandpile grid
 * @grid: Sandpile grid
 * @check: Grid used to check for cell stability
 * Return: 1 if the grid is unstable, 0 if it is stable
 */
int stability_check(int grid[3][3], int check[3][3])
{
	int i, j;
	int instable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				check[i][j] = 1;
				instable = 1;
			}
			else
				check[i][j] = 0;
		}
	}
	return (instable);
}

/**
 * sandpile_topple - Topples all unstable sandpile grid cells
 * @grid: Unstable sandpile grid
 * @check: Grid used to check for unstable cells
 * Return: Nothing
 */
void sandpile_topple(int grid[3][3], int check[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (check[i][j] == 1)
			{
				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (j + 1 < 3)
					grid[i][j + 1] += 1;
				if (i + 1 < 3)
					grid[i + 1][j] += 1;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
				grid[i][j] -= 4;
			}
		}
	}
}

/**
 * sandpiles_sum - Sums two sandpiles
 * @grid1: A sandpile grid.
 * @grid2: Another sandpile grid. The grains here will be added to @grid1
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid_check[3][3];
	int i, j, unstable;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
			{
				grid_check[i][j] = 1;
				unstable = 1;
			}
			else
				grid_check[i][j] = 0;
		}
	}
	while (unstable == 1)
	{
		printf("=\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
				{
					printf(" ");
					printf("%d", grid1[i][j]);
				}
			}
			printf("\n");
		}
		sandpile_topple(grid1, grid_check);
		unstable = stability_check(grid1, grid_check);
	}
}
