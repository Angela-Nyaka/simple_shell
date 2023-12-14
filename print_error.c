#include "shell.h"

/**
 * print_error- prints error messages to standard output
 * @counter: number of times a command is executed
 * @args: contains program name
 * @pg_name: name of the program used
 *
 * Return: void
 */
void print_error(int counter, char *args[], char *pg_name)
{
	/** print_string("sh: ");*/
	print_string(pg_name);
	print_string(" ");
	print_integer(counter);
	print_string(": ");
	print_string(args[0]);
	print_string(": ");
	print_string("not found\n");
}
