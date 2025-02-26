#include "loop.h"
#include "libs/print_lib.h"
#include "libs/memory_lib.h"
#include "libs/string_lib.h"
#include <stdio.h>

void get_prompt(struct shell_datas *shell)
{
    size_t size = 0;
    char *line = NULL_STR;
    
    print_formatted("$> ");
    if (getline(&line, &size, stdin) == -1) {
        shell->prompt = NULL_ARRAY;
        return;
    }
    int len = str_get_len(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = STR_END;
    }
    shell->prompt = str_to_array(line, ' ');
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