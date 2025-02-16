#include "../shell_datas/shell_datas.h"
#include "../lib/lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

void exe_bin(char *bin, char **commands, char **env)
{
    pid_t pid;
    int wstatus;

    pid = fork();
    if (pid == 0) {
        if (execve(bin, commands, env) == -1)
            return;
        else
            exit(0);
    } else
        wait(&wstatus);
    //if (WIFSIGNALED(wstatus))
        //get_sig(wstatus);
}

bool check_bin_command(char **commands, char **env, char *bin_path)
{
    char *bin = malloc(sizeof(char) * (str_get_len(bin_path) + str_get_len(commands[0]) + 1));

    strcpy(bin, bin_path);
    strcat(bin, commands[0]);
    int rt = open(bin, 0);

    if (rt != -1) {
        exe_bin(bin, commands, env);
        close(rt);
        return true;
    }
    return false;
}

bool check_others_command(struct shell_datas *shell)
{
    char *all_bin_paths[] = {"cd", "exit", "env", "unsetenv", "setenv", NULL};

}

void use_command(struct shell_datas *shell)
{
    char *all_bin_paths[] = {"/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/", NULL};

    if (check_others_command(shell)) {
        return;
    }

    for (int i = 0; all_bin_paths[i] != NULL; i++) {
        if (check_bin_command(shell->prompt, shell->env, all_bin_paths[i])) {
            return;
        }
    }
    printf("Unkwon command.\n");
}