#include "function_pointers.h"

/**
 * array_iterator - iterates through an array of pointers
 * print_number - function to print numbers
 * main - use to call the main function
 * @array: defines the function array
 * @action: fuction pointer
 * @size: determines size_t
 * Return: 0
 */



void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array && size > 0 && action)
		for (i = 0; i < size; i++)
			action(array[i]);
}

