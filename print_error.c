#include "shell.h"

/**
* print_error- prints error messages to standard output
* @session_counter: number of times a command is executed
* @args: contains program name
* @program_name: name of the program used
*
* Return: void
*/
void print_error(int session_counter, char *args[], char *program_name)
{
	
	print_chars(program_name);
	print_chars(" ");
	print_chars(session_counter);
	print_chars(": ");
	print_chars(args[0]);
	print_chars(": ");
	print_chars("not found\n");
}
