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
 * print_err - Function to print error message
 * @command: Command input
 * @line_cont: number of lines of commands
 * Return: nothing
 */

int print_err(char **command, int line_cont)
{
	char *num = NULL;

	num = int_to_a(line_cont);
	write(STDOUT_FILENO, "./hsh: ", 7);
	write(STDOUT_FILENO, num, _strlen(num));
	free(num);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	return (127);
}

/**
 * int_to_a - Function that converts an integer into string
 * @n: integer to convert
 * Return: String from integer
 */

char *int_to_a(int n)
{
	int i = 31, j = 0;
	char *s = NULL, *p = NULL, *t = NULL;

	s = malloc(32 * sizeof(char));
	if (s == NULL)
		return (NULL);
	s[i--] = '\0';
	s[i--] = ' ';
	s[i] = ':';
	while (n)
	{
		s[--i] = (n % 10) + '0';
		n /= 10;
	}
	p = &s[i];
	t = malloc((_strlen(p) + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	while (*p)
	{
		t[j] = *(p);
		p++, j++;
	}
	t[j] = '\0';
	free(s);
	return (t);
}
