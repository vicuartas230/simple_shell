#include "shell.h"

/**
 * call_shell - Function that calls the start of shell
 * Return: nothing
 */

void call_shell(void)
{
	int line = 0, line_cont = 0, words = 0;
	size_t chars = 0;
	char *buff = NULL, **command = NULL, *new_buff = NULL;

	if (isatty(STDIN_FILENO))
		while (line != EOF)
		{
			buff = NULL, new_buff = NULL;
			line_cont++;
			write(STDOUT_FILENO, "$ ", 2);
			line = getline(&buff, &chars, stdin);
			if (line == EOF)
			{
				free(buff);
				break;
			}
			new_buff = remove_new_line(buff);
			if (new_buff[0] == 0)
				continue;
			words = count_w(new_buff, " ");
			command = str_array(new_buff, words, " ");
			if (builtin_sel(command) == -1)
				check_command(command, line_cont);
			free(new_buff);
		}
	else
	{
		line = getline(&buff, &chars, stdin);
		new_buff = remove_new_line(buff);
		words = count_w(new_buff, " ");
		command = str_array(new_buff, words, " ");
		if (builtin_sel(command) == -1)
			check_command(command, line_cont);
		/* free(new_buff); */
	}
	free(new_buff);
	write(STDOUT_FILENO, "\n", 1);
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
			free_arr(command);
		}
		else
		{
			print_err(command, line_cont);
			free_arr(command);
		}
	}
	else
	{
		handler_dir(command, line_cont);
	}
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
	/*return (child);*/
}

/**
 * handler_dir - This function open a dir and compares its content.
 * @command: The command to compare.
 * @line_cont: The number of commands executed and not executed.
 * Return: Nothing.
 */

void handler_dir(char **command, int line_cont)
{
	int i = 0, words = 0, flag = 0;
	char **paths = NULL, *path = NULL, *cat_p = NULL, *copy = NULL;
	DIR *dir;
	struct dirent *direntp;

	copy = _getenv("PATH");
	path = _strdup(copy);
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
				free_arr(paths);
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
		print_err(command, line_cont), free_arr(command), free_arr(paths);
}
