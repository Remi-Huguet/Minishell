#include "main.h"
#include "libs/print_lib.h"
#include "libs/string_lib.h"

void show_help()
{
    print_formatted("No parameters needed to lauch the shell.\n");
    print_formatted("This program is like a linux shell in bash.\n");
    print_formatted("To run the program : mysh\n");
}

int main(int ac, char **av, char **env)
{
    if (ac == 1) {
        shell_loop(env);
    } else if (ac == 2 && str_is_same(av[1], "-h")) {
        show_help();
    } else {
        print_formatted("No parameters needed, -h no more details.\n");
    }
    return 0;
}