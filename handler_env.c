#include "shell.h"

/**
 * _getenv - This function looks for a path in the environment.
 * @command: The command of the environment variable.
 * Return: A pointer to path of the variable.
 */

char *_getenv(const char *command)
{
	unsigned int length = 0, i =  0;
	char *pos = NULL, *str = NULL;

	length = _strlen(command);
	while (environ[i])
	{
		str = environ[i];
		pos = _strchr(str, '=');
		if (pos && (pos - str == length && !_strncmp(str, command, length)))
			return (pos + 1);
		i++;
	}
	return (NULL);
}

/**
 * _setenv - This function sets a environment variable.
 * @command: The standard input.
 * Return: Nothing.
 */

void _setenv(char **command)
{
	char *s = _getenv(command[1]), *fil = NULL;

	if (s == NULL)
	{
		fil = fill(command[1], command[2]);
		putenv(fil);
		free(fil);
	}
	else
	{
		fil = fill(s, command[2]);
		putenv(fil);
		free(fil);
	}
	free_arr(command);
}

/**
 * _unsetenv - This function unsets a environment variable.
 * @command: The standard input.
 * Return: Nothing.
 */

void _unsetenv(char **command)
{
	char **ep = NULL, **sp = NULL;
	int len = 0;

	if (command[1] == NULL || command[1] == NULL ||
	_strchr(command[1], '=') != NULL)
	{
		write(STDOUT_FILENO, "not found\n", 11);
		free_arr(command);
		return;
	}
	len = _strlen(command[0]);
	ep = environ;
	while (*ep)
	{
		if (!(_strncmp(*ep, command[0], len)) && (*ep)[len + 1] == '=')
		{
			sp = ep;
			while (*sp)
			{
				*sp = *(sp + 1);
				sp++;
			}
		}
		else
			ep++;
	}
	free_arr(command);
}

/**
 * fill - This function concatenates a string with a '='.
 * @command: The string 1.
 * @value: The string 2.
 * Return: A pointer to string NULL terminated concatenated.
 */

char *fill(const char *command, const char *value)
{
	unsigned int i = 0;
	char *buff = NULL;

	buff = malloc((strlen(command) + strlen(value) + 2) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (*command)
	{
		buff[i] = *command;
		command++;
		i++;
	}
	buff[i] = '=';
	i++;
	while (*value)
	{
		buff[i] = *value;
		value++;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
