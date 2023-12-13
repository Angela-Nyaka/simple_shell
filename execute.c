#include "shell.h"

/**
 * execute_command - executes user command
 * @command: instruction from user
 *
 * Return: nothing
 */

void execute_command(const char *command)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        print_chars("Error forking process.\n");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        /* For child process */

        /* Parsing the command and its arguments */

        // Use dynamic memory allocation for arguments
        char *args[128]; /* Adjust as needed */
        int arg_count = 0;

        char *token = strtok((char *)command, " ");

        while (token != NULL)
        {
            // Handle quotes to keep arguments with spaces together
            if (token[0] == '\"')
            {
                token++; // Skip the opening quote
                char *end_quote = strchr(token, '\"');
                if (end_quote != NULL)
                {
                    *end_quote = '\0'; // Replace closing quote with null terminator
                }
            }

            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; /* NULL-terminate the arguments array */

        /* Execute the command with execve */
        if (execve(args[0], args, NULL) == -1)
        {
            perror("./shell"); // Print detailed error message
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        wait(NULL);
    }
}
