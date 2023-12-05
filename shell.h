#ifndef SHELL_H
#define SHELL_H

/*
 * Explain Later
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*
 * I'll explain later
 *
 */

void display_prompt(void);
void print_chars(const char *message);
void read_command(char *command, size_t size);
void execute_command(const char *command);


#endif
/*SHELL_H*/
