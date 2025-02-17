#include "env.h"
#include <stdio.h>

void use_env(struct shell_datas *shell)
{
    for (int i = 0; shell->env[i] != NULL; i++) {
        printf("%s\n", shell->env[i]);
    }
}