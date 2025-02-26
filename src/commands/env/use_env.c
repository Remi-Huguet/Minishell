#include "env.h"
#include "libs/print_lib.h"
#include "libs/string_lib.h"

void use_env(struct shell_datas *shell, char **command)
{
    if (shell == POINTER_ERROR || command == POINTER_ERROR) return;
    if (array_get_len(command) != 1) {
        return;
    }
    for (int i = 0; shell->env[i] != ARRAY_END; i++) {
        print_formatted("%s\n", shell->env[i]);
    }
}