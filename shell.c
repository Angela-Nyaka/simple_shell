#include "shell.h"


/*
 * 
 *1)function to write onto stdoutput
 *2) prompt the user
 *3)we use a function to read the specified command
 *4)we then execute the given command
 *
*/


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
