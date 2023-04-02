/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** mini_printf
*/

#include <stdarg.h>
#include "foxx.h"
#include "aim.h"

void print_int(int x)
{
    if (x < 0) {
        my_putchar('-');
        x = -x;
    } if (x >= 10) print_int(x / 10);
    my_putchar(x % 10 + '0');
}

void print_string(const char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        my_putchar(s[i]);
    }
}

void handle_args(const char *format, va_list args)
{
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++; switch (format[i]) {
            case 'i': case 'd':
                print_int(va_arg(args, int));
                break;
            case 'c':
                my_putchar(va_arg(args, int));
                break;
            case 's':
                print_string(va_arg(args, char*));
                break;
            case '%':
                my_putchar('%');
                break; default:
                my_putchar(format[i]); break;
            } } else {
            my_putchar(format[i]);
        }
    }
}

void mini_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    handle_args(format, args);
    va_end(args);
}
