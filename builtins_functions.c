#include "shell.h"

/**
 *
 *
 */

int builtin_sel(char **command)
{
	int i = 0;

	builtin fun_built_arr[] = {
		{"env", env},
		{"exit", f_exit},
		{NULL, NULL}
	};

	while (fun_built_arr[i].str_bltn)
	{
		if (_strcmp(command[0], fun_built_arr[i].str_bltn) == 0)
		{
			fun_built_arr[i].fun_p();
			return (0);
		}
		i++;
	}
	return (-1);
}

/**
 * _exit - This function finishes the program.
 * Return: Nothing.
 */

void f_exit(void)
{
/*	free(command);
	free(buff);*/
	exit(EXIT_SUCCESS);
}

/**
 * env - This function prints the enviroment.
 * Return: Nothing.
 */

void env(void)
{
	while (*environ)
	{
		write(STDOUT_FILENO, environ, 100);
		environ++;
	}
}
