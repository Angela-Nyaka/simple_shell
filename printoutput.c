#include "shell.h"
/**
*print_chars- prints characters
*@message: error to display
*
*Return: nothing
*/

void print_chars(const char *message)
{
	write(STDOUT_FILENO, message, _strlen(message));
}
