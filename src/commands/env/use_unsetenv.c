#include "env.h"
#include <stdio.h>
#include <stdlib.h>

void delete_env_var_at(struct shell_datas *shell, int index)
{
    int env_len = array_get_len(shell->env);

    free(shell->env[index]);
    for (int i = index; i < env_len - 1; i++) {
        shell->env[i] = shell->env[i + 1];
    }
    shell->env[env_len - 1] = NULL;
}

void use_unsetenv(struct shell_datas *shell)
{
    if (array_get_len(shell->prompt) != 2) {
        printf("unsetenv: bad usage.\n");
        return;
    }
    int index = get_env_var_index(shell->env, shell->prompt[1]);

    if (index != -1) {
        delete_env_var_at(shell, index);
    } else {
        printf("unsetenv: %s is not a env variable.\n", shell->prompt[1]);
    }
}