#include "cd.h"
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
    #include <errno.h>

bool check_dir(char *dir_to_check)
{
    DIR* dir = opendir(dir_to_check);

    if (dir) {
        closedir(dir);
    } else if (ENOENT == errno) {
        int op = open(dir_to_check, 0);

        if (op == -1) {
            printf("bash: cd: %s: no such file or directory\n", dir_to_check);
        } else {
            printf("bash: cd: %s: not a directory\n", dir_to_check);
        }
        return false;
    } else if (EACCES == errno) {
        printf("bash: cd: %s: Permission denied\n", dir_to_check);
        return false;
    }
    return true;
}

void change_dir(struct shell_datas *shell)
{
    char *old_dir = get_env_var(shell->env, "OLDPWD");
    char *current_dir = get_env_var(shell->env, "PWD");

    printf("%s\n", old_dir);
    printf("%s\n", current_dir);
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