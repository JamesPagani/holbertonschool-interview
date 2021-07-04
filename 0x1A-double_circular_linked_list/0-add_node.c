#include <stdlib.h>
#include "list.h"

/**
 * copystr - Copy a string from a source to a destination
 * @src: String to copy.
 * @dst: Destination string.
 */
void copystr(char *src, char *dst)
{
	size_t i = 0;

	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
}

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
	size_t size;

	root = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	size = 0;
	while (str[size])
		size++;
	new->str = malloc(sizeof(char) * size);
	if (new->str == NULL)
		return (NULL);
	copystr(str, new->str);

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
	size_t size;

	root = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	size = 0;
	while (str[size])
		size++;
	new->str = malloc(sizeof(char) * size);
	if (new->str == NULL)
		return (NULL);
	copystr(str, new->str);

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
