#include "shell.h"

/**
 * handler_dir - This function open a dir and compares its content.
 * @command: The command to compare.
 * @line_cont: The number of commands executed and not executed.
 * Return: Nothing.
 */

int handler_dir(char **command, int line_cont)
{
	int i = 0, words = 0, flag = 0, code = 0;
	char **paths = NULL, *path = NULL, *cat_p = NULL, *copy = NULL;
	DIR *dir;
	struct dirent *direntp;

	copy = _getenv("PATH");
	path = _strdup(copy);
	if (!path)
	{
		code = print_err(command, line_cont), free_arr(command), free(path);
		return (127);
	}
	words = count_w(path, ":");
	paths = str_array(path, words, ":");
	free(path);
	while (paths[i] && !flag)
	{
		dir = opendir(paths[i]);
		while ((direntp = readdir(dir)) != NULL)
		{
			if (_strcmp(direntp->d_name, command[0]) == 0)
			{
				cat_p = _strcat(paths[i], command[0]);
				command[0] = _strdup(cat_p);
				free(cat_p);
				under_process(command);
				free_arr(command);
				flag = 1;
				break;
			}
		}
		closedir(dir);
		i++;
	}
	if (!flag && !(paths[i]))
		code = print_err(command, line_cont), free_arr(command);
	free_arr(paths);
	return (code);
}

/**
 * under_process - This function creates a child process and
 * executes a command if it is valid.
 * @command: The command to execute.
 * Return: The process ID of the child.
 */

void under_process(char **command)
{
	int child = 0, zero = 0;

	child = fork();
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
	else
		wait(&zero);
}

/**
 * cancel_cc - This function avoid the ctrl c to exit from the shell.
 * @num: variable.
 * Return: Nothing.
 */

void cancel_cc(__attribute__((unused)) int num)
{
	signal(SIGINT, cancel_cc);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
}
