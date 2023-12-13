#include "shell.h"
#define ERR_MESSAGE "%s: %d: exit: Illegal number: %d\n"

/**
 * _builtin - executes commands that are local to the shell
 * @argument_count: number of arguments passed
 * @arguments: arguments passed to the program
 * @session_count: tracks the number of commands executed by the shell
 * @program_name: program name
 * @status: status
 *
 * Return: Returns 1 if the command is built into our shell or 0 if it is not
 */
int _builtin(int argument_count, char *arguments[], int session_count, char *pg_name, int *status)
{
    int exit_status = 0;

    if (_strcmp(arguments[0], "exit") == 0)
    {
        if (argument_count > 1)
        {
            exit_status = atoi(arguments[1]);
            if (exit_status < 0)
            {
                fprintf(stderr, ERR_MESSAGE, pg_name, session_count, exit_status);
                return 1;
            }
            exit(exit_status);
        }
        exit(*status);
    }
    else if (_strcmp(arguments[0], "env") == 0)
    {
        print_env();
        return 1;
    }
    return 0;
}
