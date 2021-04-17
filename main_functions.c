#include "shell.h"

/**
 * interactive - This function activates the interactive mode of the shell.
 * Return: The code of execution of the process.
 */

int interactive(void)
{
	int line = 0, line_cont = 0, words = 0, code = 0;
	char *buff = NULL, **command = NULL, *new_buff = NULL;
	size_t chars = 0;

	signal(SIGINT, cancel_cc);
	while (line != EOF)
	{
		buff = NULL, new_buff = NULL, line_cont++;
		write(STDOUT_FILENO, "$ ", 2);
		line = getline(&buff, &chars, stdin);
		if (line == EOF)
		{
			write(STDOUT_FILENO, "\n", 1), free(buff);
			break;
		}
		new_buff = remove_new_line(buff);
		free(buff);
		if (new_buff[0] == 0)
			continue;
		words = count_w(new_buff, " ");
		if (words == 0)
			continue;
		command = str_array(new_buff, words, " ");
		if (builtin_sel(command, new_buff, code) == -1)
			code = check_command(command, line_cont);
		free(new_buff);
	}
	free(new_buff);
	return (code);
}

/**
 * non_interactive - This functions activates the non interactive
 * mode of the shell.
 * Return: The code of execution of the process.
 */

int non_interactive(void)
{
	int  code = 0;
	unsigned int line_cont = 0, words = 0;
	char **command = NULL, *buffer = NULL, *new_buff = NULL;
	size_t chars = 0;

	while (getline(&buffer, &chars, stdin) != EOF)
	{
		line_cont++;
		if (buffer[0] == '\n')
			continue;
		new_buff = remove_new_line(buffer);
		words = count_w(new_buff, " ");
		if (!words)
		{
			free(new_buff);
			continue;
		}
		command = str_array(new_buff, words, " ");
		if (builtin_sel(command, new_buff, code) == -1)
			code = check_command(command, line_cont);
		free(new_buff);
	}
	free(buffer);
	return (code);
}

/**
 * check_command - This function checks if command exists.
 * @command: The command to check.
 * @line_cont: The number of commands executed and not executed.
 * Return: Nothing.
 */

int check_command(char **command, int line_cont)
{
	int code = 0;
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
			code = print_err(command, line_cont);
			free_arr(command);
		}
	}
	else if (!stat(command[0], &st) && !_strncmp(command[0], "./", 2))
	{
		under_process(command);
		free_arr(command);
	}
	else
	{
		code = handler_dir(command, line_cont);
	}
	return (code);
}
