#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int str_get_len(char *str);

char **str_to_array(char *str, char separator)
{
    int len = str_get_len(str);
    char **array = malloc(sizeof(char) * (len + 1));
    int arrayIndex = 0;
    int i = 0;

    while (i < len) {
        while (i < len && str[i] == separator) {
            i++;
        }
        char *line = malloc(sizeof(char) * (len + 1));
        int lineIndex = 0;
 
        while (i < len && str[i] != separator) {
            line[lineIndex] = str[i];
            i++;
            lineIndex++;
            if (i == len || str[i] == separator) {
                line[lineIndex] = '\0';
                array[arrayIndex]= strdup(line);
                arrayIndex++; 
                free(line);
            }
        }
        i++;
    }
    array[arrayIndex] = NULL;
    return array;
}