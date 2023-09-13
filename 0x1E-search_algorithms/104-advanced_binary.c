#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: Index of the first element to print in array
 * @right: Index of the last element to print in array
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}


/**
 * binary_search_recursive - Searches for a value in a sorted array of integers
 * using the Binary search algorithm (recursive version)
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary of the subarray to work on
 * @right: Right boundary of the subarray to work on
 * @value: Value to search for
 *
 * Return: The first index where value is located, or -1 on failure
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right >= left)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;
		if (array[mid] == value)
		{
			if (mid == 0 || array[mid - 1] < value)
				return (mid);
			else
				return (binary_search_recursive(array, left, mid, value));
		}
		if (array[mid] > value)
			return (binary_search_recursive(array, left, mid - 1, value));
		return (binary_search_recursive(array, mid + 1, right, value));
	}
	return (-1);
}


/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * usingi the Binary search algorithm
 * (returns the first index if value appears more than once)
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located, or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (binary_search_recursive(array, 0, size - 1, value));
}
