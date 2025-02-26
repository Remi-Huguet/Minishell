#include "macros.h"

void print_char(char c);

void print_int(int number)
{
    if (number < 0) {
        print_char('-');
        number = number * (-1);
    }
    if (number >= 10) {
        print_int(number / 10);
    }
    print_char(number % 10 + '0');
}