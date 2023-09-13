#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @low: The first index of the array/subarray to search in.
 * @high: The last index of the array/subarray to search in.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */

int binary_search(int *array, size_t low, size_t high, int value)
{
	size_t i;

	if (high >= low)
	{
		size_t mid = low + (high - low) / 2;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);

		if (array[mid] > value)
			return (binary_search(array, low, mid - 1, value));

		return (binary_search(array, mid + 1, high, value));
	}

	return (-1);
}



/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound;

	if (size == 0)
		return (-1);

	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2,
			((bound < size) ? bound : size - 1));

	return (binary_search(array, bound / 2,
				((bound < size) ? bound : size - 1), value));
}
