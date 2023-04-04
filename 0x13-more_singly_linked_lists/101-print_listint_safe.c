#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	int count = 0, i;
	const listint_t *tmp[200];

	if (!head)
		exit(98);

	while (head)
	{
		for (i = 0; i < count; i++)
		{
			if (tmp[i] == head)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				return (count);
			}
		}
		printf("[%p] %d\n", (void *)head, head->n);
		tmp[count] = head;
		count++;
		head = head->next;
	}
	return (count);
}
