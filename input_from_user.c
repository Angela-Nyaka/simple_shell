#include "shell.h"

/**
 *exit_shell- Reading user input data
 *return: nothing
 */

void exit_shell(void)
{
	print_chars("Exiting the shell.\n");
	exit(0);
}
/**
*read_command- Reading user input data
*@ex_code: input
*@size: size of characters
*
*return: nothing
*/
void read_command(char *ex_code, size_t size)
{
	if (fgets(ex_code, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_chars("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_chars("Error reading user input data.\n");
			exit(EXIT_FAILURE);
		}

	}
	/*Remove new line*/
	ex_code[strcspn(ex_code, "\n")] = '\0';

	if (_strcmp(ex_code, "exit") == 0)
	{
		exit_shell();
	}
}
