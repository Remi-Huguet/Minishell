#include "macros.h"

int str_get_len(char *str)
{
    if (str == POINTER_ERROR) return NULL_INT;
    int i = 0;

    while (str[i] != STR_END) {
        i++;
    }
    return i;
}