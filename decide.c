#include "main.h"

/**
 * decision - Decide which function to use based on specifier
 * @d: The specifier character to determine the function
 *
 * Description: This function takes a specifier character and determines
 *              which function to use based on the specifier
 *
 * Return: A function pointer based on the specifier or NULL.
 */

int (*decision(char d))(va_list)
{
	int i;
	int (*func[])(va_list) = {_string, _char, _decimal, _integer, _uinteger};
	const char specifiers[] = "scdiu";

	for (i = 0; specifiers[i]; i++)
	{
		if (d == specifiers[i])
		{
			return (func[i]);
		}
	}

	return (NULL);
}
