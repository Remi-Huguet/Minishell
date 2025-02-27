#include "pipe.h"
#include "macros.h"
#include "libs/string_lib.h"
#include "libs/print_lib.h"
#include <stdbool.h>

bool check_valid_pipe(char **command)
{
    if (command == POINTER_ERROR) return false;
    if (array_get_len(command) < 3) {
        print_formatted("Bad redirections usage : only accept format \"'command' '| or ||' 'command\"\n");
        return false;
    }
    if (str_is_same(command[0], "|") || str_is_same(command[2], "|") || str_is_same(command[array_get_len(command) - 1], "||") || str_is_same(command[array_get_len(command) - 1], "||")) {
        print_formatted("Bad redirections usage : only accept format \"'command' '| or ||' 'command\"\n");
        return false;
    }
    int count_single = 0;
    int count_double = 0;

    for (int i = 0; command[i] != ARRAY_END; i++) {
        if (str_is_same(command[i], "|")) {
            count_single++;
        }
        if (str_is_same(command[i], "||")) {
            count_double++;
        }
    }
    if (count_double + count_single != 1) {
        print_formatted("Bad redirections usage : only accept format \"'command' '| or ||' 'command\"\n");
        return false;
    }
    return true;
}

bool check_is_pipe(char **command)
{
    if (command == POINTER_ERROR) return false;
    if (!array_contain(command, "|") && !array_contain(command, "||")) {
        return false;
    }
    return true;
}

bool command_with_pipe(char **command)
{
    if (command == POINTER_ERROR) return true;
    if (!check_is_pipe(command)) {
        return false;
    }
    if (!check_valid_pipe(command)) {
        return true;
    }
    if (array_contain(command, "|")) {
        single_pipe(command);
    } else {
        double_pipe(command);
    }
    return true;
}