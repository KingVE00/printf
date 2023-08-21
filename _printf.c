#include "main.h"
#include <stdlib.h>
/**
 * _printf - functions the same as printf function
 * @format: The first fixed argument
 * @...: variable arguments
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int size, j, k;
	va_list arg_list;
	char *my_str;
	char tmp;

	k = 0;
	va_start(arg_list, format);
	for (size = 0; format[size]; size++)
	{
	}
	my_str = malloc(sizeof(format) * size);
	for (j = 0; j < size; j++)
	{
		my_str[j] = format[j];
	}
	for (j = 0; j < size; j++)
	{
		k = j;
		if (my_str[j] == '%')
		{
			if (my_str[++k] == 'c')
			{
				my_str[j] = va_arg(arg_list, int);
				my_str[k] = 3;
			}
			if (my_str[k] == '%')
			{
				my_str[++j] = 3;
			}
			if (my_str[k] == 'd' || my_str[k] == 'i')
			{
				tmp = va_arg(arg_list, int);
				my_str[j] = (tmp / 10) + '0';
				my_str[k] = (tmp % 10) + '0';
			}
		}

	}
	printf("%s", my_str);
	return (size);
}
