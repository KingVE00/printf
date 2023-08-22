#include "main.h"

int _putchar(char c)
{
    return write(1, &c, 1);
}

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

int _char(va_list args)
{
    char ch = va_arg(args, int);
    _putchar(ch);
    return 1;
}

int _decimal(va_list args)
{
    int cnt = 0;
    int dec = va_arg(args, int);
    cnt = _putdec(dec, 0);

    return cnt;
}

int _integer(va_list args)
{
    int x = va_arg(args, int);
    return _putdec(x, 0);
}

int (*decision(char d))(va_list)
{
    int (*func[])(va_list) = {_string, _char, _decimal, _integer};
    const char specifiers[] = "scdi";

    for (int i = 0; specifiers[i]; i++) {
        if (d == specifiers[i]) {
            return func[i];
        }
    }

    return NULL; // Return NULL for unknown specifiers
}

