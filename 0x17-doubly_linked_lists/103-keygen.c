#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * generate_key - Generates a key by
 * converting username to lowercase
 * @username: The input username string
 * @key: The output key string
 */

void generate_key(char *username, char *key)
{
	int i;

	for (i = 0; username[i]; i++)
	{
		key[i] = tolower(username[i]);
	}
}


/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */

int main(void)
{
	char username[100];
	char key[100];

	printf("Enter the username: ");
	fgets(username, 100, stdin);
	username[strlen(username) - 1] = '\0';

	generate_key(username, key);

	printf("The key for %s is %s\n", username, key);

	return (0);
}
