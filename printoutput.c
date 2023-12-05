#include "shell.h"

void print_chars(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

