#include "macros.h"

int array_get_len(char **array)
{
    if (array == POINTER_ERROR) return NULL_INT;
    int i = 0;

    while (array[i] != ARRAY_END) {
        i++;
    }
    return i;
}