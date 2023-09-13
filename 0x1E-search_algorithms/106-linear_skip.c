#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "search_algos.h"
#include <math.h>

/**
 * normal_lane_search - Searches for a value in the normal lane of a skip list
 * @current: A pointer to the current node in the normal lane.
 * @value: The value to search for.
 *
 * Return: A pointer to the node containing the value, or NULL if not found.
 */
skiplist_t *normal_lane_search(skiplist_t *current, int value)
{
	while (current != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

		if (current->n == value)
			return (current);

		if (current->n > value)
			break;

		current = current->next;
	}

	return (NULL);
}

/**
 * get_last_index - Gets the index of the last node in a skip list.
 * @list: A pointer to the head of the skip list.
 *
 * Return: The index of the last node or 0 if the list is empty.
 */
size_t get_last_index(skiplist_t *list)
{
	skiplist_t *last = list;
	size_t last_index = 0;

	while (last->next != NULL)
	{
		last = last->next;
		last_index = last->index;
	}

	return (last_index);
}


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
	size_t last_index;

	last_index = get_last_index(list);

	if (list == NULL)
		return (NULL);

	current = list;
	express = list->express;


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


	return (normal_lane_search(current, value));

	return (NULL);
}
