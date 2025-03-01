#include "pipe.h"
#include "macros.h"
#include "libs/string_lib.h"
#include "libs/print_lib.h"
#include "libs/memory_lib.h"
#include <stdbool.h>

bool check_valid_pipe_format(char **commands)
{
    if (commands == POINTER_ERROR) return false;
    if (array_get_len(commands) < 3) {
        print_formatted("Bad pipe usage : only accept format \"'command' '| or ||' 'command\"\n");
        return false;
    }
    if (str_is_same(commands[0], "|") || str_is_same(commands[0], "||") || str_is_same(commands[array_get_len(commands) - 1], "|") || str_is_same(commands[array_get_len(commands) - 1], "||")) {
        print_formatted("Bad pipe usage : only accept format \"'command' '| or ||' 'command\"\n");
        return false;
    }
    int count = 0;

    for (int i = 0; commands[i] != ARRAY_END; i++) {
        if (str_is_same(commands[i], "|") || str_is_same(commands[i], "||")) {
            count++;
        }
    }
    if (count != 1) {
        print_formatted("Bad pipe usage : only accept format \"'command' '| or ||' 'command\"\n");
        return false;
    }
    return true;
}

bool check_is_pipe(char **commands)
{
    if (commands == POINTER_ERROR) return false;
    if (!array_contain(commands, "|") && !array_contain(commands, "||")) {
        return false;
    }
    return true;
}

char **separate_commands_by_pipe(char **commands, bool first_command)
{
    if (commands == POINTER_ERROR) return NULL_ARRAY;
    int len = 0;
    int i = 0;

    if (!first_command) {
        for (i = 0; !str_is_same(commands[i], "|") && !str_is_same(commands[i], "||"); i++);
        i++;
        for (int y = i; commands[y] != ARRAY_END; y++) {
            len++;
        }
    } else {
        for (int y = 0; !str_is_same(commands[y], "|") && !str_is_same(commands[y], "||"); y++) {
            len++;
        }
    }
    char **command = allocate_memory(sizeof(char *) * (len + 1));
    int y = 0;
    if (command == MALLOC_ERROR) return NULL_ARRAY;

    for (y = 0; !str_is_same(commands[i], "|") && !str_is_same(commands[i], "||") && commands[i] != ARRAY_END; y++) {
        command[y] = allocate_memory(sizeof(char) * (str_get_len(commands[i]) + 1));
        command[y] = commands[i];
        i++;
    }
    command[y] = ARRAY_END;
    return command;
}

bool commands_with_pipe(struct shell_datas *shell, char **commands)
{
    if (shell == POINTER_ERROR || commands == POINTER_ERROR) return true;
    if (!check_is_pipe(commands)) {
        return false;
    }
    if (!check_valid_pipe_format(commands)) {
        return true;
    }
    if (array_contain(commands, "|")) {
        single_pipe(shell, separate_commands_by_pipe(commands, true), separate_commands_by_pipe(commands, false));
    } else {
        double_pipe(shell, separate_commands_by_pipe(commands, true), separate_commands_by_pipe(commands, false));
    }
    return true;
}