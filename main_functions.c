#include "shell.h"

/**
 * call_shell - Function that calls the start of shell
 * Return: nothing
 */

void call_shell(void)
{
	int line = 0, line_cont = 0, words = 0;
	size_t chars = 0;
	char *buff = NULL, **command = NULL;

	while (line != EOF)
	{
		line_cont++;
		write(STDOUT_FILENO, "$ ", 2);
		line = getline(&buff, &chars, stdin);
		buff[line - 1] = 0;
		words = count_w(buff, " ");
		command = str_array(buff, words, " ");
		if (builtin_sel(command) == -1)
			check_command(command, line_cont);
	}
	free(buff);
}

/**
 * under_process - This function creates a child process and
 * executes a command if it is valid.
 * @command: The command to execute.
 * Return: The process ID of the child.
 */

void under_process(char **command)
{
	int child = 0;

	child = fork();
	wait(NULL);
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (child == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	/*return (child);*/
}

/**
 * check_command - This function checks if command exists.
 * @command: The command to check.
 * @line_cont: The number of commands executed and not executed.
 * Return: Nothing.
 */

void check_command(char **command, int line_cont)
{
	struct stat st;

	if (command[0][0] == '/')
	{
		if (!stat(command[0], &st))
		{
			under_process(command);
			free(command);
		}
		else
		{
			write(STDOUT_FILENO, "sh: ", 4);
			write(STDOUT_FILENO, &line_cont, 1);
			write(STDOUT_FILENO, command[0], _strlen(command[0]));
			write(STDOUT_FILENO, ": not found\n", 12);
		}
	}
	else
	{
		handler_dir(command);
	}
}

/**
 * handler_dir - This function open a dir and compares its content.
 * @command: The command to compare.
 * @line_cont: The number of commands executed and not executed.
 * Return: Nothing.
 */

void handler_dir(char **command)
{
	int i = 0, words = 0, j = 0, k = 0;
	char **paths = NULL, *tmp = NULL, *path = NULL;
	struct stat st;

	path = _getenv("PATH");
	words = count_w(path, ":");
	paths = str_array(path, words, ":");
	while (paths[i])
	{
		tmp = malloc(sizeof(char) * 20);
		if (tmp == NULL)
			return;
		j = 0;
		while (paths[i][j])
		{
			tmp[j] = paths[i][j];
			j++;
		}
		tmp[j] = '/';
		j++;
		k = 0;
		while (command[0][k])
		{
			tmp[j] = command[0][k];
			k++;
			j++;
		}
		tmp[j] = '\0';
		if (!(stat(tmp, &st)))
		{
			command[0] = strdup(tmp);
			free(tmp);
			under_process(command);
			break;
			}
		i++;
	}
	free(paths);
/*	free(command);*/
}
