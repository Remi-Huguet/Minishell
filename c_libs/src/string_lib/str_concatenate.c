#include "macros.h"

int str_get_len(char *str);
void *allocate_memory(size_t size);

void str_concatenate(char **dest, char *str)
{
    if (dest == POINTER_ERROR || *dest == POINTER_ERROR || str == POINTER_ERROR) return;
    char *concatenated_str = allocate_memory(sizeof(char) * (str_get_len(*dest) + str_get_len(str) + 1));
    if (concatenated_str == MALLOC_ERROR) return;
    int i = 0;
    int j = 0;

    for (i = 0; (*dest)[i] != STR_END; i++) {
        concatenated_str[i] = (*dest)[i];
    }
    for (j = 0; str[j] != STR_END; j++) {
        concatenated_str[i + j] = str[j];
    }
    concatenated_str[i + j] = STR_END;
    *dest = concatenated_str;
}