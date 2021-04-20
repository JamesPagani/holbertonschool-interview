#include "sort.h"
/**
 * sift_down - Fixes the array so it satifies the heap property again.
 * @array: The heap to modify
 * @node: Node to move.
 * @curr_size: The current size of the array.
 * @real_size: The real size of the array. Used when printing it.
 */

void sift_down(int *array, size_t node, size_t curr_size, size_t real_size)
{
	size_t root = node;
	size_t left_child = 2 * root + 1;
	size_t right_child = 2 * root + 2;
	size_t swap = 0;
	int tmp;

	while (left_child < curr_size)
	{
		swap = root;
		if (array[swap] < array[left_child])
			swap = left_child;
		if (right_child < curr_size && array[swap] < array[right_child])
			swap = right_child;
		if (swap != root)
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, real_size);
			root = swap;
			left_child = 2 * root + 1;
			right_child = 2 * root + 2;
		}
		else
			break;
	}
}

/**
 * heapify - Turn the array into a valid heap tree array
 * @array: The array to heapify.
 * @size: Size of the array.
 */

void heapify(int *array, size_t size)
{
	size_t node = size - 1;

	for (; node > 0 ; node--)
	{
		sift_down(array, node, size, size);
	}
	sift_down(array, node, size, size);
}


/**
 * heap_sort - Sort the array using the heap sort algorithm
 * @array: Array to sort.
 * @size: Size of the array.
 */

void heap_sort(int *array, size_t size)
{
	size_t curr_size = size;
	int tmp = 0;

	heapify(array, size);
	while (curr_size > 1)
	{
		tmp = array[curr_size - 1];
		array[curr_size - 1] = array[0];
		array[0] = tmp;
		print_array(array, size);
		curr_size--;
		sift_down(array, 0, curr_size, size);
	}
}
