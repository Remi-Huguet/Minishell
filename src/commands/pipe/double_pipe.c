#include "macros.h"
#include "libs/print_lib.h"

void double_pipe(char **command)
{
    if (command == POINTER_ERROR) return;
    print_formatted("DOUBLE PIPE\n");
}