#include <stddef.h>

int array_get_len(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        i++;
    }
    return i;
}