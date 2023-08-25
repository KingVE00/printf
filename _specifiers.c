#include "main.h"
#include <limits.h>
#include <stdlib.h>
/**
 * _putdec - Print an integer to standard output
 * @x: The integer to be printed
 * @cnt: The count of characters printed so far
 *
 * Description: This function prints an integer to the standard output.
 *		It handles both positive and negative integers, converting
 *		them to their character representation.
 *
 * Return: The updated count of characters printed.
 */

int _putdec(int x, int cnt)
{
	int d = x;

	if (x < 0)
	{
		d = -x;
		_putchar('-');
		cnt = cnt + 1;
	}

	if (d / 10)
	{
		cnt = _putdec(d / 10, cnt);
	}

	_putchar(d % 10 + '0');
	return (cnt + 1);

}

/**
 * _string - Print a string to standard output
 * @args: The va_list containing the string to be printed
 *
 * Description: This function prints a NULL string to the standard output.
 *
 * Return: The count of characters printed.
 */

int _string(va_list args)
{
	int cnt = 0;

	char *str = va_arg(args, char*);

	while (*str)
	{
		_putchar(*str);
		str++;
		cnt++;
	}
	return (cnt);

}

/**
 * _char - Print a character to standard output
 * @args: The va_list containing the character to be printed
 *
 * Description: This function takes a character from the va_list and uses
 *		the _putchar function to print it to the standard output. *
 * Return: Always 1 (for the character printed)
 */

int _char(va_list args)
{
	char ch = va_arg(args, int);

	if (ch == '%')
		return (1);
	_putchar(ch);

	return (1);
}

/**
 * _decimal - Print an integer as a decimal to standard output
 * @args: The va_list containing the integer to be printed
 *
 * Description: This function takes an integer from the va_list, processes it,
 *		and prints it as a decimal to the standard output using the
 *		_putdec function.
 *
 * Return: The count of characters printed.
 */

int _decimal(va_list args)
{
	int cnt = 0;

	int dec = va_arg(args, int);

	cnt = _putdec(dec, 0);

	return (cnt);
}

/**
 * _integer - Print an integer to standard output
 * @args: The va_list containing the integer to be printed
 *
 * Description: This function takes an integer from the va_list and uses the
 *		_putdec function to print it to the standard output.
 *
 * Return: The count of characters printed.
 */

int _integer(va_list args)
{
	int x = va_arg(args, int);

	return (_putdec(x, 0));
}
