#include "macros.h"
#include <stdbool.h>

bool str_contain(char *str, char c)
{
    if (str == POINTER_ERROR) return false;
    for (int i = 0; str[i] != STR_END; i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}