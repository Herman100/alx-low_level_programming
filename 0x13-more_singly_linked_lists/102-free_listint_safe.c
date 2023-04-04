#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *slow, *fast, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			temp = slow;
			do {
				temp = temp->next;
				count++;
			} while (temp != slow);

			temp = *h;
			while (temp != slow)
			{
				temp = temp->next;
				count++;
			}

			*h = NULL;
			return (count);
		}
	}

	while (*h)
	{
		temp = (*h)->next;
		free(*h);
		*h = temp;
		count++;
	}

	return (count);
}

