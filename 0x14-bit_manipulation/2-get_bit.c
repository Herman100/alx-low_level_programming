#include <stdio.h>

/**
 * get_bit - gets the value of a bit at a given index
 * @n: unsigned long integer
 * @index: index starting from 0, of the bit to get
 *
 * Return: the value of the bit at the given index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(n) * 8 - 1))
		return (-1);

	return ((n >> index) & 1);
}

