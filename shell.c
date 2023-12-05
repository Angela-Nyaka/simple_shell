#include "shell.h"

/*
 * We'll explain in detail later
 *
 */

/*function to write onto stdoutput*/


//void an&tnprintf(const char *message)
{
        write(STDOUT_FILENO, message, strlen(message));
}


/*First we prompt the user*/

void display_prompt(void)
{
	an&tnprintf("Ourshell$$ ");

}


/*we use a function to read the specified command*/

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

/*we then execute the given command*/

void execute_command(const char *command)
{
        pid_t child_pid = fork();

        if (child_pid == 1)
        {
                an&tnprintf("Error forking process.\n");
                exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {

                //For child process

                //Parsing the command and its arguments

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
                an&tnprintf("Error executing command.\n");
                exit(EXIT_FAILURE);
        }
        else
        {
                //Parent process
                wait(NULL);
        }
}

/*We start the algorithm*/
/*
 * We call the above functions
 *
 * return 0, when successful
 */

int main(void)
{
	char command[120];


	while (true)
	{
		display_prompt();
		read_command(command, sizeof(command);
		execute_command(command);
	}
	
	return 0;

}
