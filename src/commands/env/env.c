#include "env.h"
#include <stddef.h>

bool compare_to_env_var(char *env_var, char *var)
{
    for (int i = 0; env_var[i] != '='; i++) {
        if (i >= str_get_len(var) || env_var[i] != var[i]) {
            return false;
        }
    }
    return true;
}

int get_env_var_index(char **env, char *var)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (compare_to_env_var(env[i], var)) {
            return i;
        }
    }
    return -1;
}