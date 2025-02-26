#include "macros.h"
#include <stdbool.h>

int array_get_len(char **array);
bool str_is_same(char *str, char *str_to_compare);

bool array_is_same(char **array, char **array_to_compare)
{
    if (array == POINTER_ERROR && array_to_compare == POINTER_ERROR) {
        return true;
    }
    if (array == POINTER_ERROR || array_to_compare == POINTER_ERROR) return false;
    if (array_get_len(array) != array_get_len(array_to_compare)) {
        return false;
    }
    for (int i = 0; array[i] != ARRAY_END; i++) {
        if (!str_is_same(array[i], array_to_compare[i])) {
            return false;
        }
    }
    return true;
}