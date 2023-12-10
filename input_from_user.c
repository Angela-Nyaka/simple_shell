#include "shell.h"

/**
 *read_command- Reading user input data
 *@command: input
 *@size: size of characters
 *
 *return: nothing
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
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
	command[strcspn(command, "\n")] = '\0';
}
