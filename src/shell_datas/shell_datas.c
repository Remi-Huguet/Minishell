#include "./shell_datas.h"
#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void init_shell_env(struct shell_datas *shell, char **env)
{
    int count = 0;
    
    while (env[count] != NULL) {
        count++;
    }
    shell->env = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i < count; i++) {
        shell->env[i] = strdup(env[i]);
    }
    shell->env[count] = NULL;
}

void init_shell_datas(struct shell_datas *shell, char **env)
{
    init_shell_env(shell, env);
    shell->exit = false;
}