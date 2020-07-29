#include <unistd.h>

/**
 * _putchar - writes to stdout
 * @c: character to write
 *
 * Return: 1 for success, else -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
