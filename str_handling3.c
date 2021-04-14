#include "shell.h"
/**
 * _strdup - This function returns a pointer to a new string which is
 * a duplicate of the string s.
 * @s: The string to duplicate.
 * Return: a pointer to the duplicated string.
 */
char *_strdup(const char *s)
{
	int i = 0;
	char *cpy = NULL;

	if (!s || !*s)
		return (NULL);
	cpy = malloc(sizeof(char) * (_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/**
 * 
 * 
 */

void print_err(char **command, int line_cont)
{
	char *num = NULL;

	num = int_to_a(line_cont);
	write(STDOUT_FILENO, "sh: ", 4);
	write(STDOUT_FILENO, num, _strlen(num));
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	/* free(num); */
}

/**
 * 
 * 
 */

char *int_to_a(int n)
{
	int i = 31;
	char *s = NULL, *p = NULL;

	s = malloc(32 * sizeof(char));
	s[i--] = '\0';
	s[i--] = ' ';
	s[i] = ':';
	while (n)
	{
		s[--i] = (n % 10) + '0';
		n /= 10;
	}
	p = &s[i];
	return (p);
}