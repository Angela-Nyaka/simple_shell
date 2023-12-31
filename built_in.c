#include "shell.h"
#define ERR "%s: %d: exit: Illegal number: %d\n"
/**
 * built_in - executes commands that are local to the shell
 * @args: arguments passed to the program
 * @argc: number of arguments passed
 * @s_c: tracks number of commands that have been executed by shell
 * @pg_name: program name
 * @st: status
 *
 * Return: Returns 1 if the command is built in our shell or 0 it it is not
 */
int built_in(int argc, char *args[], int s_c, char *pg_name, int *st)
{
	int status = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (argc > 1)
		{
			status = atoi(args[1]);
			if (status < 0)
			{
				fprintf(stderr, ERR, pg_name, s_c, status);
				return (1);
			}
			exit(status);
		}
		exit(*st);
	}

	else if (_strcmp(args[0], "env") == 0)
	{
		return (1);
	}
	return (0);
}
