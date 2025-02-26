#include "macros.h"
#include <stdbool.h>

char *str_reverse(char *str);
void print_char(char c);
void print_str(char *str);
void *reallocate_memory(void *ptr, size_t new_size);

void print_hexa(int number, bool upper)
{
    char *hexa_caracteres_lower = "abcdef";
    char *hexa_caracteres_upper = "ABCDEF";
    char *hexa = NULL_STR;
    int len = 0;

    upper = upper;
    if (number == 0) {
        print_char('0');
        return;
    }
    if (number < 0) {
        print_char('-');
        number = number * (-1);
    }
    while (number > 0) {
        int rest = number % 16;

        hexa = reallocate_memory(hexa, sizeof(char) * (len + 2));
        if (hexa == MALLOC_ERROR) return;
        if (rest > 9) {
            if (upper) {
                hexa[len] = hexa_caracteres_upper[rest - 10];
            } else {
                hexa[len] = hexa_caracteres_lower[rest - 10];
            }
        } else {
            hexa[len] = rest + '0';
        }
        hexa[len + 1] = STR_END;
        number = number / 16;
        len++;
    }
    print_str(str_reverse(hexa));
}