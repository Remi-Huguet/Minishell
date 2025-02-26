#include "macros.h"

int str_get_len(char *str);
void *allocate_memory(size_t size);

void str_copy(char **dest, char *str)
{
    if (str == POINTER_ERROR) return;
    *dest = allocate_memory(sizeof(char) * (str_get_len(str) + 1));
    if (dest == MALLOC_ERROR || dest == NULL) return;
    int i = 0;

    for (i = 0; str[i] != STR_END; i++) {
        (*dest)[i] = str[i];
    }
    (*dest)[i] = STR_END;
}