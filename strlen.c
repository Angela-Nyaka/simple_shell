#include "shell.h"
/**
 *_strlen- returns the length of a string.
 * @s: string
 *
 * Return: length of the string
 */
size_t _strlen(const char *s)
{
size_t length = 0;

while (*s != '\0')
{
length++;
s++;
}
return (length);
}
