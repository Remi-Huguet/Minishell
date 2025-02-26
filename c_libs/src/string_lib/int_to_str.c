#include "macros.h"
#include <stdbool.h>

char *str_reverse(char *str);
void *reallocate_memory(void *ptr, size_t new_size);

char *int_to_str(int number)
{
    if (number == 0) {
        return "0";
    }
    char *str = NULL_STR;
    int str_index = 0;
    bool negative = false;

    if (number < 0) {
        negative = true;
        number = number * (-1);
    }
    for (int i = 10; number > 0; i = i * 10) {
        int rest = number % i;

        if (i != 10) {
            rest = rest / (i / 10);
        }
        str = reallocate_memory(str, sizeof(char) * (str_index + 2));
        if (str == MALLOC_ERROR) return NULL_STR;
        str[str_index] =  rest + '0';
        number = number - (number % i);
        str_index++;
    }
    if (negative) {
        str = reallocate_memory(str, sizeof(char) * (str_index + 2));
        if (str == MALLOC_ERROR) return NULL_STR;
        str[str_index] = '-';
        str_index++;
    }
    str[str_index] = STR_END;
    return str_reverse(str);
}