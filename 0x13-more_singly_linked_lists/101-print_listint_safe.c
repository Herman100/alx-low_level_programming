#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to pointer to the head of the list
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (count);

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;

		/* check if current->next points back */
		if (next >= current)
		{
			*h = NULL;
			break;
		}

		current = next;
	}

	return (count);
}

