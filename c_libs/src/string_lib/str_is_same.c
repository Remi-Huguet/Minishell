#include "macros.h"
#include <stdbool.h>

int str_get_len(char *str);

bool str_is_same(char *str, char *str_to_compare)
{
    if (str == POINTER_ERROR && str_to_compare == POINTER_ERROR) {
        return true;
    }
    if (str == POINTER_ERROR || str_to_compare == POINTER_ERROR) return false;
    if (str_get_len(str) != str_get_len(str_to_compare)) {
        return false;
    }
    for (int i = 0; str[i] != STR_END; i++) {
        if (str[i] != str_to_compare[i]) {
            return false;
        }
    }
    return true;
}