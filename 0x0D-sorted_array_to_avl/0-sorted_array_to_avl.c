#include "binary_trees.h"

/**
 * clear_tree - Clear the binary tree on failure.
 * @root: Root of the sub-tree.
 */

void clear_tree(avl_t **root)
{
	if ((*root)->left != NULL)
		clear_tree(&(*root)->left);
	if ((*root)->right != NULL)
		clear_tree(&(*root)->right);
	free(*root);
}

/**
 * splice_array - Splices the array into a smaller one.
 * @array: Array to splice.
 * @min: Lower limit of the splice.
 * @hi: Upper limit of the splice.
 * Return: Spliced array, from @min to @max.
 */

int *splice_array(int *array, int min, int hi)
{
	int size = hi - min + 1;
	int i;
	int *new_array = malloc(sizeof(int) * size);

	if (new_array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		new_array[i] = array[min + i];

	return (new_array);
}

/**
 * sorted_array_to_avl - Converts a sorted array into an AVL tree.
 * @array: The array to convert.
 * @size: Size of the array.
 * Return: Root node of the (sub)tree.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new;
	int lo_lim = 0, hi_lim = size - 1, splice_size, *l_splice, *r_splice;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);
	new->n = array[((int)size - 1) / 2];
	new->left = NULL;
	new->right = NULL;

	hi_lim = ((int)size - 1) / 2 - 1;
	if (lo_lim <= hi_lim && hi_lim >= lo_lim)
	{
		l_splice = splice_array(array, lo_lim, hi_lim);
		splice_size = hi_lim - lo_lim + 1;
		new->left = sorted_array_to_avl(l_splice, splice_size);
		new->left->parent = new;
		free(l_splice);
	}
	lo_lim = ((int)size - 1) / 2 + 1;
	hi_lim = size - 1;
	if (lo_lim <= hi_lim && hi_lim >= lo_lim)
	{
		r_splice = splice_array(array, lo_lim, hi_lim);
		splice_size = hi_lim - lo_lim + 1;
		new->right = sorted_array_to_avl(r_splice, splice_size);
		new->right->parent = new;
		free(r_splice);
	}
	return (new);
}
