#include "macros.h"

int str_get_len(char *str);
char *str_duplicate(char *str);
void *allocate_memory(size_t size);
void free_memory(void *ptr);

char **str_to_array(char *str, char separator)
{
    if (str == POINTER_ERROR) return NULL_STR;
    int len = str_get_len(str);
    char **array = allocate_memory(sizeof(char *) * (len + 1));
    if (array == MALLOC_ERROR) return NULL_STR;
    int arrayIndex = 0;
    int i = 0;

    while (i < len) {
        while (i < len && str[i] == separator) {
            i++;
        }
        char *line = allocate_memory(sizeof(char) * (len + 1));
        if (line == MALLOC_ERROR) return NULL_STR;
        int lineIndex = 0;
 
        while (i < len && str[i] != separator) {
            line[lineIndex] = str[i];
            i++;
            lineIndex++;
            if (i == len || str[i] == separator) {
                line[lineIndex] = STR_END;
                array[arrayIndex]= str_duplicate(line);
                arrayIndex++; 
                free_memory(line);
            }
        }
        i++;
    }
    array[arrayIndex] = ARRAY_END;
    return array;
}