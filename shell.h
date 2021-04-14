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
/**
 * struct built - Structure for builtin commands
 * @str_bltn: string to compare with standard input
 * @fun_p: function to call the respective builtin
 */
typedef struct built
{
	char *str_bltn;
	void (*fun_p)();
} builtin;

int count_w(char *buff, char *delim);
void call_shell(void);
char **str_array(char *line, int words, char *delim);
int _strlen(const char *s);
void under_process(char **command);
void check_command(char **command, int line_cont);
void  handler_dir(char **command, int line_cont);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
int builtin_sel(char **command);
void f_exit(void);
void env(void);
void clear_s(void);
char *remove_new_line(char *buff);
void free_arr(char **command);
char *_strdup(const char *s);
void print_err(char **command, int line_cont);
char *int_to_a(int n);

#endif
