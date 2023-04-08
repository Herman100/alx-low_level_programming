#include <stdio.h>

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 *
 * @b: A pointer to a string containing a binary number.
 *
 * Return: The converted unsigned integer, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		num = num * 2 + (*b++ - '0');
	}

	return (num);
}

