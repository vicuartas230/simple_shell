#include "shell.h"
/**
 * count_w - Function that counts the words writed in terminal
 * @buff: to temporarily store the words
 * @delim: words delimiter
 * Return: the number of words
 */
int count_w(char *buff, char *delim)
{
	int step = 0;
	unsigned int words = 0;

	while (*buff)
	{
		if (*buff == delim[0] || *buff == '\n')
			step = 0;
		else if (step == 0)
		{
			step = 1;
			++words;
		}
		++buff;
	}
	return (words);
}
/**
 * str_array - Function that converts a string to a pointers array
 * @line: The string to convert
 * @words: Number of words of the array
 * @delim: Delimiter of words
 * Return: array of pointers
 */
char **str_array(char *line, int words, char *delim)
{
	char **tok = NULL;
	int i = 0;

	tok = malloc(words * sizeof(char *));
	if (tok == NULL)
		return (NULL);
	/* while (i < words)
	{
		tok[i] = NULL;
		i++;
	}
	i = 0; */
	while (i < words)
	{
		if (!i)
			tok[i] = strtok(line, delim);
		else
			tok[i] = strtok(0, delim);
		i++;
	}
	tok[i] = NULL;
	return (tok);
}
/**
 * _strlen - Function that returns the length of a string
 * @s: string of characters
 * Return: number of characters
 */

int _strlen(const char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i + 1);
}

/**
 * _strcat - This function concatenates two strings
 * @dest: The string to print
 * @src: The original string
 * Return: 0 (Success)
 */

char *_strcat(char *dest, char *src)
{
	int a, b;

	for (b = 0; dest[b] != '\0'; ++b)
		;
	for (a = 0; a <= b && src[a] != '\0'; ++a)
	{
		*(dest + (a + b)) = src[a];
	}
	dest[b + a] = '\0';
	return (dest);
}

/**
 * _strcmp - This function compares two strings
 * @s1: Character 1 to compare
 * @s2: Character 2 to compare
 * Return: 0 (Success)
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0, e = 0;

	if (_strlen(s1) == _strlen(s2))
	{
		for (a = 0; s1[a] && s2[a] != '\0'; a++)
		{
			if (s1[a] != s2[a])
			{
				e = (s1[a] - s2[a]);
				break;
			}
			else
			{
				e = 0;
			}
		}
		return (e);
	}
	return (_strlen(s1) - _strlen(s2));
}
