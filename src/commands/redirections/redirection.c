#include "macros.h"
#include "redirection.h"
#include "libs/print_lib.h"
#include "libs/string_lib.h"
#include <stdbool.h>

bool check_valid_redirection_format(char **commands)
{
    if (commands == POINTER_ERROR) return false;
    if (array_get_len(commands) < 3) {
        print_formatted("Bad redirections usage : only accept format \"'command' '< or << or > or >>' 'command\"\n");
        return false;
    }
    if (str_is_same(commands[0], "<") || str_is_same(commands[0], "<<") || str_is_same(commands[array_get_len(commands) - 1], "<") || str_is_same(commands[array_get_len(commands) - 1], "<<") \
        || str_is_same(commands[0], ">") || str_is_same(commands[0], ">>") || str_is_same(commands[array_get_len(commands) - 1], ">") || str_is_same(commands[array_get_len(commands) - 1], ">>")) {
        print_formatted("Bad redirections usage : only accept format \"'command' '< or << or > or >>' 'command\"\n");
        return false;
    }
    int count = 0;

    for (int i = 0; commands[i] != ARRAY_END; i++) {
        if (str_is_same(commands[i], "<") || str_is_same(commands[i], "<<") || str_is_same(commands[i], ">") || str_is_same(commands[i], ">>")) {
            count++;
        }
    }
    if (count != 1) {
        print_formatted("Bad redirections usage : only accept format \"'command' '< or << or > or >>' 'command\"\n");
        return false;
    }
    return true;
}

bool check_is_redirection(char **commands)
{
    if (commands == POINTER_ERROR) return false;
    if (!array_contain(commands, "<") && !array_contain(commands, "<<") && !array_contain(commands, ">") && !array_contain(commands, ">>")) {
        return false;
    }
    return true;
}

bool commands_with_redirection(struct shell_datas *shell, char **commands)
{
    if (shell == POINTER_ERROR || commands == POINTER_ERROR) return true;
    if (!check_is_redirection(commands)) {
        return false;
    }
    if (!check_valid_redirection_format(commands)) {
        return true;
    }
    print_formatted("REDIC\n");
    return true;
}