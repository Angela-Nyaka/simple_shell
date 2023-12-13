#include "shell.h"

/**
 * strchr - locate the first occurrence of a character in a string
 * @s: the string to search
 * @c: the character to find
 *
 * Return: a pointer to the first occurrence of the character,
 *         or NULL if the character is not found
 */
char *strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return (char *)s;

        s++;
    }

    /*If the character is '\0', return the address of the null terminator*/
    if ((char)c == '\0')
        return (char *)s;

    return NULL; /*Character not found*/
}
