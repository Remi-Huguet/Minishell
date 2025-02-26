#ifndef PRINT_LIB_H_
#define PRINT_LIB_H_

#include "macros.h"
#include <stdbool.h>

void print_binary(int number);
void print_char(char c);
void print_float(float number, int precision);
void print_formatted(char *str, ...);
void print_hexa(int number, bool upper);
void print_int(int number);
void print_octal(int number);
void print_str(char *str);

#endif /* !PRINT_LIB_H_ */