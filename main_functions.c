#include "shell.h"
/**
 * call_shell - Function that calls the start of shell
 * Return: nothing
 */
void call_shell(void)
{
    int line = 0, line_cont = 0, words = 0;
    size_t chars = 0;
    char *buff = NULL;
    char **command = NULL;

    while (line != EOF)
    {
        line_cont++;
        line = getline(&buff, &chars, stdin);
        words = count_w(buff, " ");
        command = str_array(buff, words, " ");
        if (under_process(command))
            wait(NULL);
        free(command);
    }
    free(buff);
}
/**
 * 
 * 
 */
int under_process(char **command)
{
    int child = 0;

    write(STDOUT_FILENO, "$ ", 2);
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
    return (child);
}