#include <unistd.h>

/**
 * _putchar - putchar functions
 * @c: argument passed
 * Return: return a character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}	

