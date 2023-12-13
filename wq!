#include "shell.h"

/**
 * run_command - executes a given command
 * @command: command to be executed
 * @counter: number of commands executed
 * @pg_name: name of the program used
 *
 * Description: This function will execute a command
 * by attempting to execute a program at the dir given
 * Return: Returns nothing
 */
void run_command(char *cmd, int counter, char *pg_name)
{
    char *args[ARGS_LIMIT];
    int arg_count = 0;
    static int exit_status;
    pid_t pid;

    /* split the command to get the program path */
    char *token = strtok(cmd, " \t\n");

    counter++;
    while (token != NULL && arg_count < ARGS_LIMIT - 1)
    {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " \t\n");
    }
    args[arg_count] = NULL;
    if (args[0] == NULL)
        return;
    if (_builtin(arg_count, args, counter, pg_name, &exit_status))
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
	print_error(session_counter, args, program_name);
	exit(EXIT_FAILURE);
    }
    else
        waitpid(process_id, &exit_status, 0);
}
