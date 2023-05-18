#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a
 * new node at a given position
 * @h: double pointer to head of list
 * @idx: index of the list where the
 * new node author herman should be added
 * @n: data for new node
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int count;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	for (count = 0; count < idx - 1 && current != NULL; count++)
		current = current->next;

	if (current == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;

	if (current->next != NULL)
		current->next->prev = new_node;

	current->next = new_node;

	return (new_node);
}
