#include "shell.h"
/**
 * count_w - Function that counts the words writed in terminal
 * @buff: to temporarily store the words
 * @delim: words delimiter
 * Return: the number of words
 */
int count_w(char *buff, char *delim)
{
	int step = 0, i = 0;
	unsigned int words = 0;

	while (buff[i])
	{
		if (buff[i] == delim[0] || buff[i] == '\n')
			step = 0;
		else if (step == 0)
		{
			step = 1;
			words++;
		}
		i++;
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
	char **tok = NULL, *cpy = NULL;
	int i = 0;

	tok = malloc((words + 1) * sizeof(char *));
	if (tok == NULL)
		return (NULL);
	while (i < words)
	{
		if (!i)
			cpy = strtok(line, delim);
		else
			cpy = strtok(NULL, delim);
		tok[i] = _strdup(cpy);
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
	return (i);
}

/**
 * _strcat - This function concatenates two strings
 * @dest: The string to print
 * @src: The original string
 * Return: 0 (Success)
 */

char *_strcat(char *dest, char *src)
{
	int a = 0, b = 0;
	char *cat = NULL;

	if (dest == NULL && src == NULL)
		return (NULL);
	cat = malloc((_strlen(src) + _strlen(dest) + 2) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	for (a = 0; dest[a] != '\0'; a++)
	{
		*(cat + a) = dest[a];
	}
	*(cat + a) = '/';
	a++;
	for (b = 0; src[b] != '\0'; b++)
	{
		*(cat + a) = src[b];
		a++;
	}
	cat[a] = '\0';
	free(src);
	return (cat);
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
