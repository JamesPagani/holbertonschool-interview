#include "lists.h"

/**
 * check_cycle - Detects if a singly linked list has a cycle.
 * @list: The head of the linked list.
 * Return: 1 if there is a cycle, 0 oterwise.
 */
int check_cycle(listint_t *list)
{
	listint_t *r;
	listint_t *t;

	if (list == NULL)
		return (0);

	r = list;
	t = list;
	while (r != NULL && t != NULL)
	{
		r = r->next;
		if (r != NULL)
			r = r->next;
		t = t->next;
		if (r == t)
		{
			r = list;
			while (r != NULL && t != NULL)
			{
				r = r->next;
				t = t->next;
				if (r == t)
					return (1);
			}
		}
	}
	return (0);
}
