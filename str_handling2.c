#include "shell.h"
/**
 * _strchr - This function locates a character in a string
 * @s: The string to check
 * @c: The character to locate
 * Return: A pointer to the first ocurrence of
 * the character c in the string s or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int a = 0;

	for (; s[a] != '\0'; a++)
	{
		if (c == s[a])
		{
			return (&(s[a]));
		}
	}
	return ('\0');
}
/**
 * _strncmp - This function compares n positions of strings s1 and s2.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 * Return: 0, if s1 and s2 are equal or The diference between s1 and s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a = 0, e = 0;

	for (; a < n; a++)
	{
		if (s1[a] != s2[a])
		{
			e = (s1[a] - s2[a]);
			break;
		}
		else
		{
			e = (0);
		}
	}
	return (e);
}

/**
 * *_strcpy - This function copies the string pontied
 * @dest: The destine of string
 * @src: The source of string
 * Return: 0 (Success)
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	for (; a <= _strlen(src); a++)
	{
		dest[a] = src[a];
	}
	return (dest);
}
/**
 * remove_new_line - This functions removes the new line in the buffer.
 * @buff: The string to check.
 * Return: Nothing.
 */
char *remove_new_line(char *buff)
{
	int i = 0;
	char *new = NULL;

	new = malloc(_strlen(buff) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (buff[i])
	{
		if (buff[i] != '\n')
			new[i] = buff[i];
		else
			new[i] = '\0';
		i++;
	}
	free(buff);
	return (new);
}
/**
 * free_arr - Function to free memory in an array of pointers
 * @command: command input
 * Return: nothing
 */
void free_arr(char **command)
{
	int i = 0;

	for (; command[i]; i++)
	{
		free(command[i]);
	}
	free(command);
}
