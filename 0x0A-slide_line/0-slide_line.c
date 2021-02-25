#include "slide_line.h"

/**
 * slide_left - Slides and merges a given array of integers to the left.
 * @line: The array of integers.
 * @size: Amount of elements in the array.
 */

void slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 1; i < (int)size; i++)
	{
		j = i;
		while (line[j - 1] == 0)
		{
			line[j - 1] = line[j];
			line[j] = 0;
			j--;
		}
		if (line[j - 1] == line[j])
		{
			line[j - 1] += line[j];
			line[j] = 0;
		}
	}
}

/**
 * slide_right - Slides and merges a given array of integers to the right.
 * @line: The array of integers.
 * @size: Amount of elements in the array.
 */

void slide_right(int *line, size_t size)
{
	int i, j;

	for (i = (int)size - 2; i >= 0; i--)
	{
		j = i;
		while (line[j + 1] == 0)
		{
			line[j + 1] = line[j];
			line[j] = 0;
			j++;
		}
		if (line[j + 1] == line[j])
		{
			line[j + 1] += line[j];
			line[j] = 0;
		}
	}
}


/**
 * slide_line - Slides and merges a given array of integers.
 * @line: The array of integers.
 * @size: Amount of elements in the array.
 * @direction: The direction to slide the elements.
 * Return: 1 on successful operation, 0 otherwise.
 */

int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}
	return (0);
}
