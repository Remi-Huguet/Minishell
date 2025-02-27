#ifndef STRING_LIB_H_
#define STRING_LIB_H_

#include "macros.h"

bool array_contain(char **array, char *str);
int array_get_len(char **array);
bool array_is_same(char **array, char **array_to_compare);
int int_to_str(int number);
void str_concatenate(char **dest, char *str);
bool str_contain(char *str, char c);
void str_copy(char **dest, char *str);
char *str_duplicate(char *str);
int str_get_len(char *str);
bool str_is_integer(char *str);
bool str_is_same(char *str, char *str_to_compare);
char *str_reverse(char *str);
char **str_to_array(char *str, char separator);
int str_to_int(char *str);

#endif /* !STRING_LIB_H_ */