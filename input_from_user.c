#include "shell.h"

/**
 *read_command- Reading user input data
 *@command: input
 *@size: size of characters
 *
 *return: nothing
 */

void exit_shell()
{
    printf("Exiting the shell.\n");
    exit(0);
}

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

	if (strcmp(command, "exit") == 0)
	{
		exit_shell();
	}
}
