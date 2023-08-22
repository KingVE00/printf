#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _putchar(char c);
int _putdec(int x, int cnt);
int _string(va_list args);
int _char(va_list args);
int _decimal(va_list args);
int _integer(va_list args);
int (*decision(char d))(va_list);
#endif
