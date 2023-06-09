#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table,
 * or NULL if something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_sorted_list - inserts a node into the sorted linked list
 * @ht: the hash table
 * @node: the node to insert
 */
void insert_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *temp;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		node->sprev = NULL;
		node->snext = NULL;
		return;
	}

	temp = ht->shead;
	while (temp != NULL)
	{
		if (strcmp(node->key, temp->key) <= 0)
		{
			node->sprev = temp->sprev;
			node->snext = temp;
			if (temp->sprev != NULL)
				temp->sprev->snext = node;
			else
				ht->shead = node;
			temp->sprev = node;
			return;
		}
		temp = temp->snext;
	}

	node->sprev = ht->stail;
	node->snext = NULL;
	ht->stail->snext = node;
	ht->stail = node;
}



/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || value == NULL || strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	insert_sorted_list(ht, new_node);

	return (1);
}




/**
 * shash_table_print - prints a sorted hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *sep = "";

	if (ht == NULL)
		return;

	printf("{");
	temp = ht->shead;
	while (temp != NULL)
	{
		printf("%s'%s': '%s'", sep, temp->key, temp->value);
		sep = ", ";
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *sep = "";

	if (ht == NULL)
		return;

	printf("{");
	temp = ht->stail;
	while (temp != NULL)
	{
		printf("%s'%s': '%s'", sep, temp->key, temp->value);
		sep = ", ";
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *temp, *next;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			next = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next;
		}
	}
	free(ht->array);
	free(ht);
}
