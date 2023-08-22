#include "main.h"

int _printf(const char *format, ...)
{
	int cnt = 0;
    int i = 0;
    va_list args;
    va_start(args, format);

    while (format[i] != '\0') {
        if (format[i] == '%'){
            if (format[i + 1] != '\0') {
                int (*function)(va_list) = decision(format[i + 1]);
                if (function != NULL) {
                    cnt += function(args);
                    i++;
                } else {
                    _putchar(format[i]);
                    cnt++;
                }
            }
        } else {
            _putchar(format[i]);
            cnt++;
        }
        i++;
    }

    va_end(args);
    return cnt;
}
