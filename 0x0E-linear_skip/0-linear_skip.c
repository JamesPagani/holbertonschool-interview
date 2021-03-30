#include "search.h"

/**
 * print_info - Prints information about the current node.
 * @n: Current node.
 */

void print_info(skiplist_t *n)
{
	printf("Value checked at index [%d] = [%d]\n", (int)n->index, n->n);
}

/**
 * express_skip - Search for a value in a skip list through the express lane.
 * @list: Pointer to the head of the list.
 * @value: Value to search.
 * Return: Node closest to the value.
 */
skiplist_t *express_skip(skiplist_t *list, int value)
{
	skiplist_t *i = list;
	skiplist_t *j = list;
	int i_idx = 0, j_idx = 0;

	while (i->express != NULL)
	{
		j = i;
		i = i->express;
		i_idx = (int)i->index;
		j_idx = (int)j->index;
		print_info(i);
		if (i->n > value)
			break;
	}
	if (i->n < value)
	{
		j_idx = i_idx;
		for (; i->next != NULL; i = i->next);
		i_idx = i->index; 
	}
	printf("Value found between indexes [%d] and [%d]\n", j_idx, i_idx);
	return (j);
}


/**
 * linear_skip - Search for a value in a skip list.
 * @list: Pointer to the head of the list.
 * @value: Value to search
 * Return: First node which contains the value.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *guide = NULL;
	if (list == NULL)
		return (NULL);

	guide = express_skip(list, value);
	while (guide != NULL)
	{
		print_info(guide);
		if (guide->n == value)
			return (guide);
		guide = guide->next;
	}
	return NULL;
}
