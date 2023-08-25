#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int percent(va_list);
int _printf(const char *format, ...);
int _putchar(int c);
int _putdec(int x, int cnt);
int _string(va_list args);
int _char(va_list args);
int _decimal(va_list args);
int _integer(va_list args);
int _uinteger(va_list args);
int putoct(int, int);
int octal(va_list args);
int puthex(int, int);
int hex(va_list);
int (*decision(char d))(va_list);
#endif
