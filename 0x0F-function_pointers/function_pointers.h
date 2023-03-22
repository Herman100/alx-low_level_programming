#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stdio.h>


/**
 * print_name - prints the name to std
 * @name: input name
 * @f: a function pointer
 * Return: 0
 */

void print_name(char *name, void (*f)(char *));

/**
 * array_iterator - iterates through an array of pointers
 * @array: defines the function array
 * @action: fuction pointer
 * @size: determines size_t
 * Return: 0
 */

void array_iterator(int *array, size_t size, void (*action)(int));





#endif
