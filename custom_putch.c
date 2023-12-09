#include "main.h"

int _putch(char c)
{
	return (write(1, &c, 1));
}
