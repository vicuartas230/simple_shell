#include "shell.h"

/**
 * _getenv - This function looks for a path in the environment.
 * @name: The name of the environment variable.
 * Return: A pointer to path of the variable.
 */

char *_getenv(const char *name)
{
	unsigned int length = 0, i =  0;
	char *pos = NULL, *str = NULL;

	length = _strlen(name) - 1;
	while (environ[i])
	{
		str = environ[i];
		pos = _strchr(str, '=');
		if (pos && (pos - str == length && !_strncmp(str, name, length)))
			return (pos + 1);
		i++;
	}
	return (NULL);
}
