#include "../shell_datas/shell_datas.h"
#include "../lib/lib.h"
#include "../signals/signals.h"
#include "../commands/commands.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

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
    int len = str_get_len(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    shell->prompt = str_to_array(line, ' ');
    free(line);
}

void shell_loop(char **env)
{
    struct shell_datas shell;

    init_shell_datas(&shell, env);
    while (!shell.exit) {
        handle_control_c();
        get_prompt(&shell);
        if (array_get_len(shell.prompt) > 0) {
            use_command(&shell);
        }
    }
}