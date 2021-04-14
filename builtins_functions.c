#include "shell.h"

/**
 * builtin_sel - Structure for builtin commands
 * @command: command input
 * @new_buff: getline buffer
 * Return: 0 if is bultin or -1 for not
 */

int builtin_sel(char **command, char *new_buff)
{
	int i = 0;

	builtin fun_built_arr[] = {
		{"env", _env},
		{"exit", f_exit},
		{NULL, NULL}
	};

	while (fun_built_arr[i].str_bltn)
	{
		if (_strcmp(command[0], fun_built_arr[i].str_bltn) == 0)
		{
			fun_built_arr[i].fun_p(command, new_buff);
			return (0);
		}
		i++;
	}
	return (-1);
}

/**
 * f_exit - This function finishes the program.
 * @command: command input
 * @new_buff: getline buffer
 * Return: Nothing.
 */

void f_exit(char **command, char *new_buff)
{
	free_arr(command);
	free(new_buff);
	exit(EXIT_SUCCESS);
}

/**
 * _env - This function prints the enviroment.
 * @command: command input
 * Return: Nothing.
 */

void _env(char **command)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_arr(command);
}
