#include "shell.h"

void an&tnprintf(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

