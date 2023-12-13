#include "shell.h"
/**
 * print_chars - prints a string to the std out
 * @chars: string to be printed
 *
 * Return: Returns void
 */

void print_chars(const char *chars)
{
	size_t string_len = 0;
	const char *chars_ptr = chars;
	ssize_t bytes_written = 0;

	while (*chars_ptr != '\0')
	{
		string_len++;
		chars_ptr++;
	}

	bytes_written = write(STDOUT_FILENO, chars, string_len);

	if (bytes_written == -1)
		exit(EXIT_FAILURE);
}
