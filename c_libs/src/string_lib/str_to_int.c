#include "macros.h"
#include <stdbool.h>

int str_get_len(char *str);
bool str_is_integer(char *str);

int str_to_int(char *str) {
    if (str == POINTER_ERROR) return NULL_INT;
    if (!str_is_integer(str)) {
        return NULL_INT;
    }
    int res = 0;
    int index = str_get_len(str) - 1;
    int mult = 1;

    for (index = index; index >= 0; index--) {
        if (str[index] == '-') {
            return res * (-1);
        }
        res = res + ((str[index] - '0') * mult);
        mult = mult * 10;
    }
    return res;
}