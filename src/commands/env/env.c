#include "env.h"
#include "libs/string_lib.h"
#include "libs/memory_lib.h"

bool compare_to_env_var(char *env_var, char *var)
{
    int i = 0;

    for (i = 0; env_var[i] != '='; i++) {
        if (i >= str_get_len(var) || env_var[i] != var[i]) {
            return false;
        }
    }
    if (var[i] != STR_END) {
        return false;
    } 
    return true;
}

int get_env_var_index(char **env, char *var)
{
    for (int i = 0; env[i] != ARRAY_END; i++) {
        if (compare_to_env_var(env[i], var)) {
            return i;
        }
    }
    return -1;
}

char *get_env_var(char **env, char *var)
{
    for (int i = 0; env[i] != ARRAY_END; i++) {
        if (compare_to_env_var(env[i], var)) {
            int var_len = 0;

            for (var_len = 0; env[i][var_len] != '='; var_len++);
            var_len++;
            char *value = allocate_memory(sizeof(char) * (str_get_len(env[i]) - var_len));
            int value_index = 0;

            for (value_index = 0; var_len != str_get_len(env[i]); value_index++) {
                value[value_index] = env[i][var_len];
                var_len++;
            }
            value[value_index] = STR_END;
            return value;
        }
    }
    return NULL;
}