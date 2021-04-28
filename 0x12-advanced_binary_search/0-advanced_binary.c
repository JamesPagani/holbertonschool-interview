#include "search_algos.h"

/**
 * print_array - Print an integer array.
 * @array: The array to print.
 * @size: Size of the array.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_sub - Continuation of the binary search algorithm
 * @a: Sorted integer sub-array.
 * @s: Size of the sub-array.
 * @v: Number to find.
 * @idx: Real index of the sub-array's first index.
 * Return: First index where @value is found.
 */
int binary_sub(int *a, size_t s, int v, size_t idx)
{
	int left;
	int right;
	int mid;

	if (a == NULL || s == 0)
		return (-1);
	left = 0;
	right = s - 1;
	mid = right / 2;

	print_array(a, s);

	if (a[left] == v)
		return (left + idx);
	if (a[mid] >= v)
		return (binary_sub(a, s / 2, v, idx));
	else
		return (binary_sub(&a[mid + 1], s / 2, v, idx + mid + 1));
}

/**
 * advanced_binary - Binary search algorithm
 * @array: SORTED integer array
 * @size: Size of the array.
 * @value: Number to find.
 * Return: First index where @value is found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int left;
	int right;
	int mid;

	if (array == NULL || size == 0)
		return (-1);
	left = 0;
	right = size - 1;
	mid = right / 2;

	print_array(array, size);

	if (array[left] == value)
		return (left);

	if (array[mid] >= value)
		return (binary_sub(array, size / 2, value, 0));
	else
		return (binary_sub(&array[mid + 1], size / 2, value, mid + 1));
	return (-1);
}
