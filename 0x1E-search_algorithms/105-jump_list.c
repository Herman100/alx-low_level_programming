#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *             the Jump search algorithm.
 * @list: A pointer to the head of the list to search in.
 * @size: The number of nodes in list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where value is located.
 *
 * Description: Uses the square root of the size of the list as the jump step
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, i;
	listint_t *prev, *node;

	if (list == NULL)
		return (NULL);

	jump = sqrt(size);
	prev = node = list;

	while (node->index < size - 1 && node->n < value)
	{
		prev = node;
		for (i = 0; i < jump && node->next != NULL; i++)
			node = node->next;
		printf("Value checked at index [%lu] = [%d]\n",
				node->index, node->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, node->index);

	while (prev->index < size - 1 && prev->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, prev->n);
		prev = prev->next;
	}

	if (prev != NULL && prev->n == value)
		return (prev);

	return (NULL);
}
