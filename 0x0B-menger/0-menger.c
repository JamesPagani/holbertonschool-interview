#include "menger.h"

/**
 * menger_valid - Determine if it's valid to draw in the current position.
 * @row: Current row of the sponge.
 * @col: Current column of the sponge.
 * @level: Level of the sponge.
 * @size: Size of the sponge.
 * Return: 1 if it is valid to draw in the current coordinate. 0 otherwise.
 */
int menger_valid(int row, int col, int level, int size)
{
	int divR;
	int divC;
	int divident, i;

	divR = row;
	divC = col;
	divident = size;

	for(i = level; i > 0; i--)
	{
		divident /=  3;
		if (divR / divident == 1 && divC / divident == 1)
		{
			return 0;
			break;
		}
		divR %= divident;
		divC %= divident;
	}
	return 1;
}

/**
 * menger - Draws a 2D level N meger sponge on the terminal.
 * @level: Level of the sponge.
 */

void menger(int level)
{
	int size, i, j;

	if (level == 0)
	{
		putchar('#');
		putchar('\n');
	}
	else
	{
		size = pow(3, level);
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (menger_valid(i, j, level, size))
					putchar('#');
				else
					putchar(' ');
			}
			putchar('\n');
		}
		
	}
	
}
