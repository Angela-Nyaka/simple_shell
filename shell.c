#include "shell.h"
/**
 * main - program start point
 * @argc: number of arguments passed
 * @argv: arguments passed
 *
 * Description: this is the starting point of the ashell,
 * It receives program invocations and arguments
 * and executes the requested for program and its arguments
 * Return: Returns 0 on successful execution
 */
int main(int argc, char *argv[])
{
	char *cmd = NULL;
	ssize_t read_byte = 0;
	size_t buffer_size = 0;
	static int counter = 1;
	int ispiped = 0;

	(void) argc;
	(void) argv;
	--counter;
	if (!isatty(STDIN_FILENO))
		ispiped = 1;

	if (!ispiped)
		print_string("$ ");

	while ((read_byte = _getline
				(&cmd, &buffer_size, stdin)) != EOF)
	{
		if (read_byte == 1)
		{
			if (!ispiped)
				counter++;
		}
		else
		{
			if (cmd[read_byte - 1] == '\n')
				cmd[read_byte - 1] = '\0';

			run_command(cmd, counter, argv[0]);
			counter++;
		}
		if (!ispiped)
			print_string("$ ");
	}
	if (read_byte <= 0 && !ispiped)
		_putchar('\n');
	free(cmd);
	return (0);
}
