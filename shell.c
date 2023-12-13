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
	char ex_code[400];


	while (true)
	{
		command_prompt();
		read_command(ex_code, sizeof(ex_code));
	if (_strcmp(ex_code, "exit") == 0)
	{
		break;
	}
	execute_command(ex_code);
	}
	return (0);

}
