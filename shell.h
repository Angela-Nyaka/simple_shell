#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARGS_LIMIT 1024
#define ER_MSG "%s: %d: %s: not found\n"

/*extrnal variable used for execve function*/

extern char **environ;

void command_prompt(void);
void print_chars(const char *message);
void read_command(char *command, size_t size);
 void run_command(char *cmd, int counter, char *pg_name);
size_t  _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _builtin(int argument_count, char *arguments[], int session_count, char *pg_name, int *status);
void print_chars(const char *chars);
 void print_error(int session_counter, char *args[], char *program_name);
#endif
