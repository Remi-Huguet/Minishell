#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void set_env_var_at(struct shell_datas *shell, int index)
{
    int new_var_len = 0;

    for (new_var_len = 0; shell->env[index][new_var_len] != '='; new_var_len++);
    new_var_len++;
    if (array_get_len(shell->prompt) == 3) {
        new_var_len += str_get_len(shell->prompt[2]);
    }
    shell->env[index] = malloc(sizeof(char) * new_var_len);
    strcpy(shell->env[index], shell->prompt[1]);
    strcat(shell->env[index], "=");
    if (array_get_len(shell->prompt) == 3) {
        strcat(shell->env[index], shell->prompt[2]);
    }
}

void create_env_var(struct shell_datas *shell)
{
    int env_len = array_get_len(shell->env);
    int new_var_len = str_get_len(shell->prompt[1]) + 1;

    shell->env = realloc(shell->env, sizeof(char *) * (env_len + 1));
    if (array_get_len(shell->prompt) == 3) {
        new_var_len += str_get_len(shell->prompt[2]);
    }
    shell->env[env_len] = malloc(sizeof(char) * (new_var_len + 1));
    strcpy(shell->env[env_len], shell->prompt[1]);
    strcat(shell->env[env_len], "=");
    if (array_get_len(shell->prompt) == 3) {
        strcat(shell->env[env_len], shell->prompt[2]);
    }
    shell->env[env_len + 1] = NULL;
}

void use_setenv(struct shell_datas *shell)
{
    if (array_get_len(shell->prompt) < 2 || array_get_len(shell->prompt) > 3) {
        printf("setenv: bad usage.\n");
        return;
    }
    int index = get_env_var_index(shell->env, shell->prompt[1]);

    if (index != -1) {
        set_env_var_at(shell, index);
    } else {
        create_env_var(shell);
    }
}