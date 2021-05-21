#include "binary_trees.h"

/**
 * height - Retrieve the height of a node, based on the deepest child found.
 * @root: Root of the binary heap.
 * Return: Height of the node.
 */
int height(heap_t *root)
{
	int left_h = 0;
	int right_h = 0;

	if (root == NULL)
		return (0);
	if (root->left)
		left_h = 1 + height(root->left);
	if (root->right)
		right_h = 1 + height(root->right);
	return (left_h > right_h ? left_h : right_h);
}

/**
 * next_node - Get the next node to replace the root.
 * @root: Root of the binary heap.
 * Return: Pointer to a node in the heap.
 */
heap_t *next_node(heap_t *root)
{
	int left_h = 0;
	int right_h = 0;

	if (root == NULL)
		return (NULL);
	if (root->left == NULL && root->right == NULL)
		return (root);

	if (root->left)
		left_h = 1 + height(root->left);
	if (root->right)
		right_h = 1 + height(root->right);

	if (left_h - right_h > 0)
		return (next_node(root->left));
	else
		return (next_node(root->right));
	return (NULL);
}

/**
 * fix_heap - Fix the heap property of the heap tree
 * @root: Root of the binary heap
 */
void fix_heap(heap_t **root)
{
	heap_t *current = *root;
	heap_t *next;
	int tmp;

	if (current->left != NULL)
	{
		next = current->left;
		if (current->right)
		{
			if (current->right->n > next->n)
				next = current->right;
		}
		if (next->n > current->n)
		{
			tmp = next->n;
			next->n = current->n;
			current->n = tmp;
			fix_heap(&next);
		}
	}
}

/**
 * heap_extract - Extract the root node of the binary heap.
 * @root: Root of the binary heap.
 * Return: Value stored at the node.
 */
int heap_extract(heap_t **root)
{
	heap_t *root_ref = *root;
	heap_t *replace;
	int root_val;

	if (root == NULL)
		return (0);
	replace = next_node(root_ref);
	root_val = root_ref->n;

	if (replace->parent->left == replace)
		replace->parent->left = NULL;
	else
		replace->parent->right = NULL;
	replace->parent = NULL;

	replace->left = root_ref->left;
	replace->right = root_ref->right;
	if (replace->left)
		replace->left->parent = replace;
	if (replace->right)
		replace->right->parent = replace;

	free(*root);
	*root = replace;
	fix_heap(root);
	return (root_val);
}
