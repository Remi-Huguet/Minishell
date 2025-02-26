#include "env.h"
#include "libs/print_lib.h"

void use_env(struct shell_datas *shell)
{
    for (int i = 0; shell->env[i] != ARRAY_END; i++) {
        print_formatted("%s\n", shell->env[i]);
    }
}