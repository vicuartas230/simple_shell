#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>

extern char **environ;

int count_w(char *buff, char *delim);
void call_shell(void);
char **str_array(char *line, int words, char *delim);
int _strlen(char *s);
int under_process(char **command);

#endif