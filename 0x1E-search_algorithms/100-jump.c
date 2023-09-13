#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1
 * if value is not present or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump;
	size_t i, j;

	if (!array)
		return (-1);

	/* Calculate jump length */
	jump = sqrt(size);

	/* Find the block where element is present (if it is present) */
	i = 0;
	while (i < size && array[i] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i += jump;
	}

	/* Perform linear search for value in block beginning with i */
	j = i < jump ? 0 : i - jump;
	printf("Value found between indexes [%lu] and [%lu]\n", j, i);
	while (j <= i && j < size)
	{
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
		j++;
	}

	return (-1);
}
