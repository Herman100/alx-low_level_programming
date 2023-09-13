#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "search_algos.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node
 * where `value` is located or NULL if not found.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express;
	skiplist_t *last = list;
	size_t last_index = 0;

	if (list == NULL)
		return (NULL);

	current = list;
	express = list->express;

	while (last->next != NULL)
	{
		last = last->next;
		last_index = last->index;
	}

	while (express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				express->index, express->n);

		if (express->n >= value)
			break;

		current = express;
		express = express->express;
	}

	if (express == NULL)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, last_index);
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
				current->index, express->index);
	}


	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		if (current->n == value)
			return (current);
		if (current->n > value)
			break;

		current = current->next;
	}

	return (NULL);
}
