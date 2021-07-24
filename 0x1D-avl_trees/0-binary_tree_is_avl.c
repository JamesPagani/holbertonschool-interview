#include "binary_trees.h"

/**
 * height - Height of the current node.
 * @node: Node to inspect.
 * Return: Height of the tree in relation to the deepest node.
 */
int height(const binary_tree_t *node)
{
	int left_h = 0, right_h = 0;

	if (node->left)
		left_h = 1 + height(node->left);
	if (node->right)
		right_h = 1 + height(node->right);
	return (left_h >= right_h ? left_h : right_h);
}

/**
 * balance_factor - Calculate the balance factor of a tree
 * @tree: Tree to inspect.
 * Return: Positive value if the tree leans to the left, negative value if
 * the tree leans to the right, zero if the tree is balanced.
 */
int balance_factor(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree->left)
		left_h = 1 + height(tree->left);
	if (tree->right)
		right_h = 1 + height(tree->right);
	return (right_h - left_h);
}

/**
 * sub_tree_is_avl - Check if a sub tree is a valid AVL Tree
 * @root: Root of the whole tree.
 * @sub: Root of the sub tree.
 * Return: 1 if the sub tree is a valid AVL tree, 0 if otherwise.
 */
int sub_tree_is_avl(const binary_tree_t *root, binary_tree_t *sub)
{
	int balance;
	binary_tree_t *node, *prev;

	node = sub->parent;
	prev = sub;
	while (node && prev != root)
	{
		if (node->left)
		{
			if (node->left == prev)
			{
				if (sub->n > node->n || sub->n == node->n)
					return (0);
			}
		}
		if (node->right)
		{
			if (node->right == prev)
			{
				if (sub->n <= node->n || sub->n == node->n)
					return (0);
			}
		}
		prev = node;
		node = node->parent;
	}

	balance = balance_factor(sub);
	if (balance > 1 || balance < -1)
		return (0);
	if (sub->left)
		if (sub_tree_is_avl(root, sub->left) == 0)
			return (0);
	if (sub->right)
		if (sub_tree_is_avl(root, sub->right) == 0)
			return (0);
	return (1);
}

/**
 * binary_tree_is_avl - Check if a tree is a valid AVL Tree
 * @tree: Root of the tree.
 * Return: 1 if the tree is a valid AVL Tree, 0 if otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (0);

	balance = balance_factor(tree);
	if (balance > 1 || balance < -1)
		return (0);

	if (tree->left)
		if (sub_tree_is_avl(tree, tree->left) == 0)
			return (0);
	if (tree->right)
		if (sub_tree_is_avl(tree, tree->right) == 0)
			return (0);

	return (1);
}
