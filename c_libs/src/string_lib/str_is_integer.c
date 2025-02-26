#include "macros.h"
#include <stdbool.h>

int str_get_len(char *str);

bool str_is_integer(char *str)
{
    if (str == POINTER_ERROR) return NULL_INT;
    int i = 0;

    if (str_get_len(str) > 1 && str[0] == '-') {
        i++;
    }
    for (i = i; str[i] != STR_END; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}