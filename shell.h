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
int _strlen(const char *s);
int under_process(char **command);
void check_command(char **command, int line_cont);
void  handler_dir(char **command);
char *_strstr(char *haystack, char *needle);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);

#endif
