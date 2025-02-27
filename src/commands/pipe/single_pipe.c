#include "macros.h"
#include "libs/print_lib.h"

void single_pipe(char **command)
{
    if (command == POINTER_ERROR) return;
    print_formatted("SINGLE PIPE\n");
}