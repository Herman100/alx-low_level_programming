#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1 at a given index
 *
 * @n: pointer to the unsigned long int to modify
 * @index: the index of the bit to set
 *
 * Return: 1 on success, -1 on failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(*n) * 8 - 1))
		return (-1);

	*n |= (1 << index);

	return (1);
}
