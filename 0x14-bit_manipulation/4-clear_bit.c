#include <stdio.h>

/**
 * clear_bit - Sets the bit at a given index to 0.
 * @n: Pointer to the unsigned long int to modify.
 * @index: The index of the bit to clear.
 *
 * Return: 1 on success, -1 on failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(*n) * 8 - 1))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}

