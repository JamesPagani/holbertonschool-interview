#include "lists.h"
/**
 * insert_node - Place a new number/node into a sorted singly linked list
 * @head: Head of the linked list
 * @number: Number to insert into the linked list
 * Return: On success, the address of the new node. On failure, NULL.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *new;

	node = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (new->n <= (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	while (node->next != NULL)
	{
		if (new->n <= node->next->n)
		{
			new->next = node->next;
			node->next = new;
			return (new);
		}
	node = node->next;
	}
	node->next = new;
	new->next = NULL;
	return (new);
}
