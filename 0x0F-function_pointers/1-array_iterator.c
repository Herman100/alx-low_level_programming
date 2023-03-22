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


#include <stdio.h>

void array_iterator(int *array, size_t size, void (*action)(int))
{
	for (size_t i = 0; i < size; i++)
	{

	action(array[i]);

	}
}

void print_number(int num)
{

	printf("%d\n", num);

}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(arr) / sizeof(int);

	array_iterator(arr, size, print_number);
	return (0);
}

