#include "shell.h"

/*
 * Explain later
 *
 */

void execute_command(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == 1)
	{
		print_chars("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{

		/*For child process*/

		/*Parsing the command and its arguments*/

		char *args[128]; /* Maximum 128 arguments, adjust as needed*/
		int arg_count = 0;

		char *token = strtok((char *)command, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;/*NULL-terminate the arguments array*/

		/*Execute the command*/
		execvp(args[0], args);

		/*If execvp fails, print an error message*/
		print_chars("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Parent process*/
		wait(NULL);
	}
}
