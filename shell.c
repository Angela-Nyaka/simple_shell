#include "shell.h"


/*
*
*1)function to write onto stdoutput
*2) prompt the user
*3)we use a function to read the specified command
*4)we then execute the given command
*
*/


/**
*main - excutes shell commands
*
*Return: nothing
*/

int main(void)
i{
	char command[120];


	while (true)
	{
		command_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);

}
