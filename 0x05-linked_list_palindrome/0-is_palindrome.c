#include "lists.h"

/**
 * listint_t_length - Calculate the length of a singly linked list
 * @head: Head of the linked list
 * Return: Length of the linked list
 */

int listint_t_length(listint_t *head)
{
	int counter;
	listint_t *node;

	node = head;

	while (node != NULL)
	{
		node = node->next;
		counter++;
	}

	return (counter);
}

/**
 * is_palindrome - Check whenever a singly linked list is a palindrome
 * @head: Head of the linked list
 * Return: 1 if the list is a palindrome, 0 if not
 */

int is_palindrome(listint_t **head)
{
	int length, i, rev_position;
	int odd = 0;
	int *first_vals;
	listint_t *node;

	if (head == NULL || *head == NULL)
		return (1);
	if ((*head)->next == NULL)
		return (1);
	node = *head;
	length = listint_t_length(node);
	first_vals = malloc(sizeof(int) * (length / 2));
	if (length % 2 != 0)
		odd = 1;
	i = 0;
	while (node != NULL)
	{
		if (i < length / 2)
			first_vals[i] = node->n;
		else
		{
			rev_position = length / 2 - (i - length / 2) - 1 + odd;
			if (i == length / 2 && length % 2 != 0)
			{
				node = node->next;
				i++;
				continue;
			}
			else if (first_vals[rev_position] != node->n)
			{
				return (0);
			}
		}
		node = node->next;
		i++;
	}

	return (1);
}
