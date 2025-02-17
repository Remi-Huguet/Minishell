#include "../shell_datas/shell_datas.h"
#include "../lib/lib.h"
#include "../signals/signals.h"
#include "./env/env.h"
#include "./cd/cd.h"
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
    check_signal(wstatus);
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

void exit_shell(struct shell_datas *shell)
{
    shell->exit = true;
}

bool check_others_command(struct shell_datas *shell)
{
    char *no_bin_commands[] = {"cd", "exit", "env", "unsetenv", "setenv", NULL};
    void (*commands[5]) (struct shell_datas *) = {use_cd, exit_shell, use_env, use_unsetenv, use_setenv};

    for (int i = 0; no_bin_commands[i] != NULL; i++) {
        if (strcmp(no_bin_commands[i], shell->prompt[0]) == 0) {
            (*commands[i])(shell);
            return true;
        }
    }
    return false;
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