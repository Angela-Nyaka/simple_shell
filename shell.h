#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/*extrnal variable used for execve function*/

/*extern char **environ;*/

void command_prompt(void);
void print_chars(const char *message);
void read_command(char *ex_code, size_t size);
/*void execute_command(const char *command);*/
void execute_command(const char *ex_code);
char *strchr(const char *s, int c);
size_t  _strlen(const char *s);
int _strcmp(char *s1, char *s2);

#endif
