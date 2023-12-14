#include "shell.h"
#include <stdint.h>
/**
 * read_chars - custom getline to accept input from the
 * standard input stream
 * @line_ptr: pointer to the line to be retrieved from standard input
 * @buf_sz: current size of the buffer
 * @t: size of buffer for storing input file
 * @stream: standard stream from which input is to be read
 * @buffer_pos: current buffer possion
 * @buffer: preloaded input of stream
 *
 * Return: Returns the number of lines read on success
 */

ssize_t read_chars(char **line_ptr, size_t *t, char *buffer,
		size_t *buffer_pos, size_t *buf_sz, FILE *stream)
{
	size_t i = 0;
	int n;
	char *new_ptr = NULL;

	while (1)
	{
		if (*buffer_pos >= *buf_sz)
		{
			*buffer_pos = 0;
			*buf_sz = read(fileno(stream), buffer, BUF_SIZE);
			if (*buf_sz == 0)
				break;
			else if (*buf_sz == SIZE_MAX)
				return (-1);
		}
		n = buffer[(*buffer_pos)++];
		if (i >= *t - 1)
		{
			*t *= 2;
			new_ptr = (char *) realloc(*line_ptr, *t);
			if (new_ptr == NULL)
				return (-1);
			*line_ptr = new_ptr;
		}
		(*line_ptr)[i++] = n;

		if (n == '\n')
			break;
	}

	if (i == 0)
		return (-1);
	(*line_ptr)[i] = '\0';
	return (i);
}
