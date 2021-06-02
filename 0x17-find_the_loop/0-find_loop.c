#include "lists.h"

/**
 * find_listint_loop - Find where a loop begins in a linked list.
 * @head: Head of the linked list.
 * Return: The address of the node where the loop start or NULL if no loop was
 * found.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *h;
	listint_t *t;

	if (!head)
		return (NULL);
	h = head;
	t = head;

	while (h)
	{
		h = h->next;
		if (h)
			h = h->next;
		t = t->next;
		if (h == t)
		{
			h = head;
			while (h != t)
			{
				h = h->next;
				t = t->next;
			}
			return (h);
		}
	}
	return (NULL);
}
