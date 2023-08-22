#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int cnt = 0;
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
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
    }

    va_end(args);
    return cnt;
}
