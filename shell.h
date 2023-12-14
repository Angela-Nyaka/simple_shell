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
#define BUF_SIZE 128


/*void command_prompt(void);*/
/*void print_chars(const char *message);*/
/*void read_command(char *ex_code, size_t size);*/
/*void execute_command(const char *command);*/
/*void execute_command(const char *ex_code);*/
/*char *strchr(const char *s, int c);*/
/*size_t  _strlen(const char *s);*/
/*int _strcmp(char *s1, char *s2);*/
int main(int argc, char *argv[]);
void run_command(char *cmd, int counter, char *pg_name);
void print_string(const char *str);
void print_error(int counter, char *args[], char *pg_name);
int built_in(int argc, char *args[], int s_c, char *pg_name, int *st);
void print_integer(int num);
int _strcmp(char *s1, char *s2);
ssize_t _getline(char **line_ptr, size_t *t, FILE *stream);
ssize_t read_chars(char **line_ptr, size_t *t, char *buffer,
		size_t *buffer_pos, size_t *buf_sz, FILE *stream);
int _putchar(char c);
int built_in(int argc, char *args[], int s_c, char *pg_name, int *st);
#endif
