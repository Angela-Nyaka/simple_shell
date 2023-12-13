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
{
	char command[120];


	while (true)
	{
		command_prompt();
		read_command(command, sizeof(command));
	if (_strcmp(command, "exit") == 0)
	{
		break;
	}
	run_command(cmd, counter, argv[0]);
	}
	return (0);

}
