#include "../shell_datas/shell_datas.h"
#include "../lib/lib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void get_prompt(struct shell_datas *shell)
{
    size_t size = 0;
    char *line = NULL;
    
    printf("$> ");
    if (getline(&line, &size, stdin) == -1) {
        shell->prompt = NULL;
        free(line);
        return;
    }
    shell->prompt = str_to_array(line, ' ');
    free(line);
}

void shell_loop(char **env)
{
    struct shell_datas shell;
    
    while (true) {
        get_prompt(&shell);
    }
}