#include "lists.h"
/**
 * _putchar - Writes a character to standard output
 * @c: The character to be written
 *
 * Description: This function writes a single character to the standard output
 *              (usually the console) using the write system call.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */

int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _uinteger - prints unsigned integer numbers
 * @args: The va_list containing the integer to be printed
 * Return: number of printed characters
 */

int _uinteger(va_list args)
{
	unsigned long x = (unsigned int)va_arg(args, int);

	x = -x;
	return (_putdec(x, 0));
}
