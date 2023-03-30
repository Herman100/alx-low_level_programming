#include <stdio.h>

/**
 * premain - this function prints a statement before the
 * main function i sexecuted.
 */

void __attribute__ ((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
