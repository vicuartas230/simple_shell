#include "shell.h"

/**
 * builtin_sel - Structure for builtin commands
 * @command: command input
 * Return: 0 if is bultin or -1 for not
 */

int builtin_sel(char **command)
{
	int i = 0;

	builtin fun_built_arr[] = {
		{"env", env},
		{"exit", f_exit},
		{"clear", clear_s},
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
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * clear_s - This function clears the screen.
 * Return: Nothing.
 */

void clear_s(void)
{
	system("clear");
  /* const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12); */
}