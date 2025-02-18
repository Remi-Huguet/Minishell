#include "cd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

bool check_dir(char *dir_to_check)
{
    if (chdir(dir_to_check) == -1) {
        switch (errno) {
            case EACCES:
                printf("bash: cd: %s: Permission denied\n", dir_to_check);
                break;
            case ENOTDIR:
                printf("bash: cd: %s: Not a directory\n", dir_to_check);
                break;
            case ENOENT:
                printf("bash: cd: %s: No such file or directory\n", dir_to_check);
                break;
            default:
                printf("bash: cd: %s: Unknown error\n", dir_to_check);
        }
        return false;
    }
    return true;
}

void change_dir(struct shell_datas *shell)
{
    char *old_pwd = get_env_var(shell->env, "PWD");
    size_t size = sizeof(char) * (str_get_len(old_pwd) + str_get_len(shell->prompt[1]) + 2);
    char *new_pwd = malloc(size);

    set_env_var(shell, "OLDPWD", old_pwd);
    getcwd(new_pwd, size);
    set_env_var(shell, "PWD", new_pwd);
    free(new_pwd);
}

void use_cd(struct shell_datas *shell)
{
    if (array_get_len(shell->prompt) == 1) {
        return;
    }
    if (array_get_len(shell->prompt) > 2) {
        printf("bash: cd: too many arguments\n");
        return;
    }
    if (!check_dir(shell->prompt[1])) {
        return;
    }
    change_dir(shell);
}