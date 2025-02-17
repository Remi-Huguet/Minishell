#include "main.h"
#include <string.h>
#include <stdio.h>

void show_help()
{
    printf("No parameters needed to lauch the shell.\n");
    printf("This program is like a linux shell in bash.\n");
    printf("To run the program : mysh\n");
}

int main(int ac, char **av, char **env)
{
    if (ac == 1) {
        shell_loop(env);
    } else if (ac == 2 && strcmp(av[1], "-h") == 0) {
        show_help();
    } else {
        printf("No parameters needed, -h no more details.\n");
    }
    return 0;
}