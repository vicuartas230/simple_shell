#include "shell.h"

/**
 * main - Entry point.
 * Return: 0 (Success)
 */

int main(void)
{
	int code = 0;

	if (isatty(STDIN_FILENO))
		code = interactive();
	else
		code = non_interactive();
	return (code);
}
