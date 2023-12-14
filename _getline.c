#include "shell.h"
/**
 * _getline - custom getline to accept input from the
 * standard input stream
 * @line_ptr: pointer to the line to be retrieved from standard input
 * @t: current size of the buffer
 * @stream: standard stream from which input is to be read
 *
 * Return: Returns the number of lines read on success
 */

ssize_t _getline(char **line_ptr, size_t *t, FILE *stream)
{
	static char buffer[BUF_SIZE];
	static size_t buf_pos;
	static size_t buf_sz;
	ssize_t bytes_read = 0;

	if (line_ptr == NULL || t == NULL || stream == NULL)
		return (-1);

	if (*line_ptr == NULL)
	{
		*t = 128;
		*line_ptr = (char *)malloc(*t);

		if (*line_ptr == NULL)
			return (-1);
	}
	bytes_read = read_chars(line_ptr, t, buffer, &buf_pos, &buf_sz, stream);
	return (bytes_read);
}
