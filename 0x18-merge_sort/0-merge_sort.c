#include "sort.h"
/**
 * print_subarray - Print a sub-array.
 * @array: Array to print.
 * @start: Starting index.
 * @end: Exclusive end index.
 */
void print_subarray(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}


/**
 * split - Split the array before merging it.
 * @array: Main array.
 * @tmp: Temporal array.
 * @start: Start of current sub array.
 * @end: End of current sub array (EXCLUSIVE).
 */
void split(int *array, int *tmp, size_t start, size_t end)
{
	size_t mid;
	if(end - start > 1)
	{
		mid = (end + start) / 2;
		split(tmp, array, start, mid);
		split(tmp, array, mid, end);
		printf("Merging...\n");
		merge(array, tmp, start, mid, end);
	}
}

/**
 * merge - Merge together two split arrays while sorting it.
 * @dest: Merging array.
 * @src: Where the unsorted and split numbers come from.
 * @start: Start of left sub-array.
 * @mid: End of left sub-array (EXCLUSIVE) and start of right sub-array.
 * @end: End of right sub-array (EXCLUSIVE).
 */
void merge(int *dest, int *src, size_t start, size_t mid, size_t end)
{
	size_t i, j, k;

	i = start;
	j = mid;

	printf("[left]: ");
	print_subarray(src, start, mid);
	printf("[right]: ");
	print_subarray(src, mid, end);
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || src[i] < src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_subarray(dest, start, end);
}

/**
 * merge_sort - Sort an array using the TOP-DOWN merge sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;
	size_t i;

	tmp = malloc(sizeof(int) * size);
	if (tmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			tmp[i] = array[i];
		}
	}
	split(array, tmp, 0, size);
	free(tmp);
}
