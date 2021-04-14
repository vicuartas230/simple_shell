<img src="https://www.holbertonschool.com/holberton-logo.png">

# Simple Shell

-   Foundations - Holberton School
-   By Victor Cuartas and Andrea Castrillón

## 📄  Overview 

It is a command interpreter, a computer program that provides an interface between the user and the operating system allowing access to its services.

## 💻  Shell functions

-   Display a prompt and wait for the user to type a command. A command line always ends with a new line.

 `andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$`
-   The prompt is displayed again each time a command has been executed.

 `andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$ /bin/ls
AUTHORS  README.md  builtins_functions.c  handler_env.c  hsh  main.c  main_functions.c  sh_manual  shell.h  str_handling.c  str_handling2.c  str_handling3.c
$ `
-   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
-   The command lines are made only of one word. No arguments will be passed to programs.
-   If an executable cannot be found, print an error message and display the prompt again.

 `andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$ /bin/hsjd
sh: /bin/hsjd: not found
$ `
-   Handle errors.
-   You have to handle the “end of file” condition (`Ctrl+D`)

 `andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$ /bin/hsjd
sh: /bin/hsjd: not found
$
andrecast@MED-PF1NQ8WJ:~/simple_shell$`
-  Handle command lines with arguments

 `andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$ /bin/ls -la -tr README.md
-rw-r--r-- 1 andrecast andrecast 15 Apr 10 09:32 README.md
$ `
-  Handle the  `PATH`
-  Implement the  `exit`  built-in, that exits the shell

`andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$ /bin/ls -la -tr README.md
-rw-r--r-- 1 andrecast andrecast 15 Apr 10 09:32 README.md
$ exit
andrecast@MED-PF1NQ8WJ:~/simple_shell$`
-  Implement the  `env`  **built-in**, that prints the current environment

 `andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
$ env
SHELL=/bin/bash
COLORTERM=truecolor
TERM_PROGRAM_VERSION=1.55.1
WSL_DISTRO_NAME=Ubuntu-20.04
NAME=MED-PF1NQ8WJ
PWD=/home/andrecast/simple_shell
LOGNAME=andrecast
VSCODE_GIT_ASKPASS_NODE=/home/andrecast/.vscode-server/bin/08a217c4d27a02a5bcde898fd7981bda5b49391b/node
MOTD_SHOWN=update-motd
HOME=/home/andrecast
LANG=C.UTF-8`


## 💡  Usage example

Let's use the **ps** command for listing proccess actually in execution:

    andrecast@MED-PF1NQ8WJ:~/simple_shell$ ./hsh
    $ ps
      PID TTY          TIME CMD
     4496 pts/3    00:00:00 bash
     5762 pts/3    00:00:00 hsh
     5763 pts/3    00:00:00 ps
    $ 

Shelley also works in non-interactive mode:

  

## ✏️ Functions used

| Function| Description |
|--|--|
| call_shell | `Function that calls the start of shell` |
|check_command |`This function checks if command exists` |
|under_process|`This function creates a child process and`|
|handler_dir |`This function open a dir and compares its content`|
|count_w |`Function that counts the words writed in terminal`|
|str_array |`Function that converts a string to a pointers array`|
|_strlen |`Function that returns the length of a string`|
|_strcat |`This function concatenates two strings`|
|_strcmp |`This function compares two strings`|
|_strchr |`This function locates a character in a string`|
|_strncmp |`This function compares n positions of strings s1 and s2`|
|*_strcpy |`This function copies the string pontied`|
|remove_new_line |`This functions removes the new line in the buffer`|
|free_arr|`Function to free memory in an array of pointers`|
|_strdup |`This function returns a pointer to a new string which is a duplicate of the string s`|
|_getenv |`This function looks for a path in the environment`|
|builtin_sel |`Structure for builtin command`|
|f_exit |`This function finishes the program`|
|env |`This function prints the enviroment`|
|clear_s |`This function clears the screen`|
|print_err | `Function to print error message` |
|int_to_a |`Function that converts an integer into string`|



## 📈 Flowchart 

-   Simple Shell

[https://drive.google.com/file/d/1hTc2UefJ6vC0fjqGmLy5DBt1ys1bKdiA/view?usp=sharing](https://drive.google.com/file/d/1hTc2UefJ6vC0fjqGmLy5DBt1ys1bKdiA/view?usp=sharing)

## 📌 About 
Created on  `Ubuntu 14.04 LTS`. Compiled with  `gcc 4.8.4`, in this way:  `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
