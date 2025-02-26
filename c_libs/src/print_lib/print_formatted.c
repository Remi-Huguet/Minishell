#include "macros.h"
#include "libs/print_lib.h"
#include <stdarg.h>
#include <stdbool.h>

bool str_contain(char *str, char c);
int str_get_len(char *str);

void print_var(va_list *args, char flag)
{
    switch ( flag ) {
        case 's':
            char *str = va_arg(*args, char *);
            
            if (str) {
                print_str(str);
            }
            break;
        case 'c':
            char c = va_arg(*args, int);
            
            if (c) {
                print_char(c);
            }
            break;
        case 'd':
            int digit = va_arg(*args, int);
            
            if (digit) {
                print_int(digit);
            }
            break;
        case 'i':
            int integer = va_arg(*args, int);
            
            if (integer) {
                print_int(integer);
            }
            break;
        case 'o':
            int octal = va_arg(*args, int);
            
            if (octal) {
                print_octal(octal);
            }
            break;
        case 'x':
            int hexa_lower = va_arg(*args, int);
            
            if (hexa_lower) {
                print_hexa(hexa_lower, false);
            }
            break;
        case 'X':
            int hexa_upper = va_arg(*args, int);
            
            if (hexa_upper) {
                print_hexa(hexa_upper, true);
            }
            break;
        case '%':
            print_char('%');
            break;
        case 'b':
            int binary = va_arg(*args, int);

            if (binary) {
                print_binary(binary);
            }
            break;
        case 'f':
            float number = va_arg(*args, double);

            if (number) {
                print_float(number, 6);
            }
            break;
        default:
            break;
    }
}

char get_flag(char *str, int index)
{
    if (index > 0 && str[index - 1] == '%') {
        return NULL_CHAR;
    }
    if (str[index + 1] == STR_END) {
        return NULL_CHAR;
    }
    return str[index + 1];
}

void print_formatted(char *str, ...)
{
    if (str == POINTER_ERROR) return;
    char flags[11] = {'s', 'c', 'd', 'i', 'o', 'x', 'X', '%', 'b', 'f', STR_END};

    va_list args;
    va_start(args, str);
    for (int i = 0; str[i] != STR_END; i++) {
        char flag = NULL_CHAR;

        if (str[i] == '%') {
            flag = get_flag(str, i);
        }
        if (flag != NULL_CHAR) {
            if (str_contain(flags, flag)) {
                print_var(&args, flag);
                i++;
            }
        } else {
            print_char(str[i]);
        }
    }
    va_end(args);
}