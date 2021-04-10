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
	unsigned words = 0;

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
	return words;
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
	while (i < words)
    {
        tok[i] = strtok(line, delim);
		i++;
    }
    return (tok);
}
/**
 * _strlen - Function that returns the length of a string
 * @s: string of characters
 * Return: number of characters

int _strlen(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i + 1);
}
*/
