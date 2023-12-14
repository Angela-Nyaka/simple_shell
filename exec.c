#include "shell.h"
/**
 * run_command - executes a given command
 * @cmd: command to be executed
 * @counter: number of commands executed
 * @pg_name: name of the porgram used
 *
 * Description: This function will execute a command
 * by attempting to execute a programm at the dir given
 * Return: Returns nothing
 */
void run_command(char *cmd, int counter, char *pg_name)
{
	char *args[ARGS_LIMIT];
	int argc = 0;
	static int exit_status;
	pid_t pid;

	/* split the command to get the program path */
	char *token = strtok(cmd, " \t\n");

	counter++;
	while (token != NULL && argc < ARGS_LIMIT - 1)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	args[argc] = NULL;
	if (args[0] == NULL)
		return;
	if (built_in(argc, args, counter, pg_name, &exit_status))
		return;
	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, NULL);
		print_error(counter, args, pg_name);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &exit_status, 0);
}
