#include "main.h"
/**
 * _putchar - Writes a character to standard output
 * @c: The character to be written
 *
 * Description: This function writes a single character to the standard output
 *              (usually the console) using the write system call.
 *
 * Return: On success, 1 is returned. On error, -1 is returned.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
