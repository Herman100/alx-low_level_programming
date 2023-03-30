#include <stdio.h>

void __attribute__ ((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}

int main(void)
{
	/* ... */
	return (0);
}

