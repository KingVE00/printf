#include "main.h"

/**
 * _putdec - Print an integer to standard output
 * @x: The integer to be printed
 * @cnt: The count of characters printed so far
 *
 * Return: The updated count of characters printed
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

    if (d/10)
    {
        cnt = _putdec(d/10, cnt);
    }

    _putchar(d%10 + '0');
    return cnt + 1;

}

/**
 * _string - Print a string to standard output
 * @args: The va_list containing the string to be printed
 *
 * Return: The count of characters printed
 */

int _string(va_list args)
{
    int cnt = 0;
    char *str = va_arg(args,char*);

    while (*str)
    {
        _putchar(*str);
        str++;
        cnt++;
    }
    return cnt;

}

/**
 * _char - Prints a character to standard output
 * @args: The va_list containing the char to be printed
 *
 * Return: The  characters to be  printed
 */

int _char(va_list args)
{
    char ch = va_arg(args, int);
    _putchar(ch);
    return 1;
}

/**
 * _decimal - Prints a decimal to standard output
 * @args: The va_list containing the decimal to be printed
 *
 * Return: The count of characters printed
 */

int _decimal(va_list args)
{
    int cnt = 0;
    int dec = va_arg(args, int);
    cnt = _putdec(dec, 0);

    return cnt;
}

/**
 * _integer - Prints an integer to standard output
 * @args: The va_list containing the integer to be printed
 *
 * Return: The count of characters printed
 */

int _integer(va_list args)
{
    int x = va_arg(args, int);
    return _putdec(x, 0);
}

/**
 * decision - Decide which function to use based on specifier
 * @d: The specifier character to determine the function
 *
 * Return: A function pointer based on the specifier
 *         or NULL for unknown specifiers
 */

int (*decision(char d))(va_list)
{
    int (*func[])(va_list) = {_string, _char, _decimal, _integer};
    const char specifiers[] = "scdi";

    for (int i = 0; specifiers[i]; i++) {
        if (d == specifiers[i]) {
            return func[i];
        }
    }

    return NULL;
}
