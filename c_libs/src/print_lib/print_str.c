#include "macros.h"
#include <unistd.h>

void print_char(char c);

void print_str(char *str)
{
    if (str == NULL_STR) return;
    int i = 0;

    while (str[i] != '\0') {
        print_char(str[i]);
        i++;
    }
}