#include "env.h"
#include "libs/print_lib.h"
#include "libs/memory_lib.h"
#include "libs/string_lib.h"

void delete_env_var_at(struct shell_datas *shell, int index)
{
    int env_len = array_get_len(shell->env);

    free_memory(shell->env[index]);
    for (int i = index; i < env_len - 1; i++) {
        shell->env[i] = shell->env[i + 1];
    }
    shell->env[env_len - 1] = ARRAY_END;
}

void use_unsetenv(struct shell_datas *shell)
{
    if (array_get_len(shell->prompt) != 2) {
        print_formatted("bash: unsetenv: bad usage.\n");
        return;
    }
    int index = get_env_var_index(shell->env, shell->prompt[1]);

    if (index != -1) {
        delete_env_var_at(shell, index);
    } else {
        print_formatted("bash: unsetenv: %s is not a env variable.\n", shell->prompt[1]);
    }
}