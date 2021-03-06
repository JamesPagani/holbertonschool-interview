#include "binary_trees.h"

/**
 * reorder - Reorders the nodes to respect a Max heap ordering.
 * @node: Node to re arrange.
 * Return: Pointer of the node where the newly inserted value is.
 */
heap_t *reorder(heap_t **node)
{
	heap_t *guide = *node;
	int tmp = 0;

	if (guide->parent == NULL)
		return (guide);
	while (guide->parent != NULL)
	{
		if (guide->n > guide->parent->n)
		{
			tmp = guide->parent->n;
			guide->parent->n = guide->n;
			guide->n = tmp;

		}
		else
			break;
		guide = guide->parent;
	}
	return (guide);
}

/**
 * count - Count the amount of nodes in the heap.
 * @root: Root of the (sub)binary heap.
 * Return: Amount of nodes in the heap.
 */
int count(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + (count(root->left) + count(root->right)));
}

/**
 * balance - Calculate the balance factor of a binary heap
 * @root: Root of the (sub)binary heap.
 * Description: The balance factor, in this case, is based by weight.
 * A positive balance factor means the tree is unbalanced from the left side.
 * A negative balance factor means the tree is unbalanced from the right side.
 * A zero balance factor means the tree is balanced.
 * Return: Balance factor of the tree.
 */
int balance(heap_t *root)
{
	int weight_l = 0;
	int weight_r = 0;

	if (root == NULL)
		return (0);
	weight_l = count(root->left);
	weight_r = count(root->right);
	return (weight_l - weight_r);
}

/**
 * heap_insert - Insert a node in a (max) binary heap.
 * @root: Root of the (sub)binary heap.
 * @value: Value of the new node.
 * Return: Pointer to the new node on success; NULL if something fails.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	heap_t *new;

	node = *root;
	if (node == NULL)
	{
		new = binary_tree_node(node, value);
		if (new == NULL)
			return (NULL);
		*root = new;
	}
	else
	{
		while (node->left != NULL && node->right != NULL)
		{
			if (balance(node) != 0)
			{
				if (balance(node->left) == 0)
					node = node->right;
				else
					node = node->left;
			}
			else
				node = node->left;
		}
		new = binary_tree_node(node, value);
		if (new == NULL)
			return (NULL);
		new->left = NULL;
		new->right = NULL;
		if (node->left == NULL)
			node->left = new;
		else
			node->right = new;
	}
	return (reorder(&new));
}
