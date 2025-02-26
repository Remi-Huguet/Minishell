#include "./shell_datas.h"
#include "libs/memory_lib.h"
#include "libs/string_lib.h"

void init_shell_env(struct shell_datas *shell, char **env)
{
    if (env == POINTER_ERROR || shell == POINTER_ERROR) return;
    int count = 0;
    
    while (env[count] != ARRAY_END) {
        count++;
    }
    shell->env = allocate_memory(sizeof(char *) * (count + 1));
    if (shell->env == MALLOC_ERROR) return;
    for (int i = 0; i < count; i++) {
        shell->env[i] = str_duplicate(env[i]);
    }
    shell->env[count] = ARRAY_END;
}

void init_shell_datas(struct shell_datas *shell, char **env)
{
    init_shell_env(shell, env);
    shell->exit = false;
}