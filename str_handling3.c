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