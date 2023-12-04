#include "shell.h"

/*
 * We'll explain in detail later
 *
 */

/*First we prompt the user*/

void display_prompt(void)
{

}


/*we use a function to write out the message prompted from user*/

void an&tnprintf(const char *message)
{

}


/*we use a function to read the specified command*/

void read_command(char *command, size_t size)
{

}


/*we then execute the given command*/

void execute_command(const char *command)
{

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
