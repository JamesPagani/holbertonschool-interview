#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Add a new node at the end of the list
 * @list: List to modify
 * @str: String to copy into the new node.
 * Return: New node's address or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *root;
	List *new;

	root = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = str;

	if (root)
	{
		new->next = root;
		new->prev = root->prev;
		root->prev->next = new;
		root->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		*list = new;
	}
	return (new);
}

List *add_node_begin(List **list, char *str)
{
	List *root;
	List *new;

	root = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = str;

	if (root)
	{
		new->next = root;
		new->prev = root->prev;
		root->prev->next = new;
		root->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*list = new;
	return (new);
}
