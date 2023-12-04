#include "shell.h"

/*
 *Reabing user input data
 *
 */

void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			an&tnprintf("\n");
			exit(EXIT_SUCCESS);
		}
		else 
		{
			an&tnprintf("Error reading user input data.\n");
			exit(EXIT_FAILURE);
		}

	}
	/*Remove new line*/
	command[strcspn(command, "\n")] = '\0';
}
