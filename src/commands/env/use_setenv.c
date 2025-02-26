#include "env.h"
#include "libs/print_lib.h"
#include "libs/memory_lib.h"
#include "libs/string_lib.h"

void create_env_var(struct shell_datas *shell)
{
    if (shell == POINTER_ERROR) return;
    int env_len = array_get_len(shell->env);
    int new_var_len = str_get_len(shell->prompt[1]) + 1;

    shell->env = reallocate_memory(shell->env, sizeof(char *) * (env_len + 1));
    if (shell->env == MALLOC_ERROR) return;
    if (array_get_len(shell->prompt) == 3) {
        new_var_len += str_get_len(shell->prompt[2]);
    }
    shell->env[env_len] = allocate_memory(sizeof(char) * (new_var_len + 1));
    if (shell->env[env_len] == MALLOC_ERROR) return;
    str_copy(&shell->env[env_len], shell->prompt[1]);
    str_concatenate(&shell->env[env_len], "=");
    if (array_get_len(shell->prompt) == 3) {
        str_concatenate(&shell->env[env_len], shell->prompt[2]);
    }
    shell->env[env_len + 1] = STR_END;
}

void set_env_var_at(struct shell_datas *shell, int index, char *new_value, char *var)
{
    if (shell == POINTER_ERROR || new_value == POINTER_ERROR || var == POINTER_ERROR) return;
    int new_var_len = 0;

    for (new_var_len = 0; shell->env[index][new_var_len] != '='; new_var_len++);
    new_var_len++;
    if (new_value != NULL_STR) {
        new_var_len += str_get_len(new_value);
    }
    shell->env[index] = allocate_memory(sizeof(char) * new_var_len);
    if (shell->env[index] == MALLOC_ERROR) return;
    str_copy(&shell->env[index], var);
    str_concatenate(&shell->env[index], "=");
    if (new_value != NULL) {
        str_concatenate(&shell->env[index], new_value);
    }
}

void set_env_var(struct shell_datas *shell, char *var, char *value)
{
    if (shell == POINTER_ERROR || var == POINTER_ERROR || value == POINTER_ERROR) return;
    int index = get_env_var_index(shell->env, var);

    if (index != -1) {
        set_env_var_at(shell, index, value, var);
    } else {
        create_env_var(shell);
    }
}

void use_setenv(struct shell_datas *shell)
{
    if (shell == POINTER_ERROR) return;
    if (array_get_len(shell->prompt) < 2 || array_get_len(shell->prompt) > 3) {
        print_formatted("bash: setenv: bad usage.\n");
        return;
    }
    set_env_var(shell, shell->prompt[1], shell->prompt[2]);
}