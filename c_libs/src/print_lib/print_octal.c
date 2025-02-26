#include "macros.h"

void print_int(int number);
void print_char(char c);

void print_octal(int number)
{
    int octal = 0;
    int mult = 1;

    if (number == 0) {
        print_char('0');
        return;
    }
    if (number < 0) {
        print_char('-');
        number = number * (-1);
    }
    while (number > 0) {
        octal = octal + ((number % 8) * mult);
        mult = mult * 10;
        number = number / 8;
    }
    print_int(octal);
}