#include "macros.h"
#include <stdbool.h>

bool str_is_same(char *str, char *str_to_compare);

bool array_contain(char **array, char *str)
{
    if (array == POINTER_ERROR || str == POINTER_ERROR) return false;
    for (int i = 0; array[i] != ARRAY_END; i++) {
        if (str_is_same(array[i], str)) {
            return true;
        }
    }
    return false;
}