#include "commands.h"
#include "libs/print_lib.h"
#include "libs/memory_lib.h"
#include "libs/string_lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

void exe_bin(char *bin, char **command, char **env)
{
    if (bin == POINTER_ERROR || command == POINTER_ERROR || env == POINTER_ERROR) return;
    pid_t pid;
    int wstatus;

    pid = fork();
    if (pid == 0) {
        if (execve(bin, command, env) == -1)
            return;
        else
            exit(0);
    } else
        wait(&wstatus);
    check_signal(wstatus);
}

bool check_bin_command(char **command, char **env, char *bin_path)
{
    if (command == POINTER_ERROR || env == POINTER_ERROR || bin_path == POINTER_ERROR) return false;
    char *bin = allocate_memory(sizeof(char) * (str_get_len(bin_path) + str_get_len(command[0]) + 1));
    if (bin == MALLOC_ERROR) return false;

    str_copy(&bin, bin_path);
    str_concatenate(&bin, command[0]);
    int rt = open(bin, 0);

    if (rt != -1) {
        exe_bin(bin, command, env);
        close(rt);
        free_memory(bin);
        return true;
    }
    free_memory(bin);
    return false;
}

bool all_bin_commands(char **command, char **env)
{
    if (env == POINTER_ERROR || command == POINTER_ERROR) return false;
    char *all_bin_paths[] = {"/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/", ARRAY_END};

    for (int i = 0; all_bin_paths[i] != ARRAY_END; i++) {
        if (check_bin_command(command, env, all_bin_paths[i])) {
            return true;
        }
    }
    return false;
}

void exit_shell(struct shell_datas *shell, char **command)
{
    if (shell == POINTER_ERROR || command == POINTER_ERROR) return;
    shell->exit = true;
}

bool others_command(struct shell_datas *shell, char **command)
{
    if (shell == POINTER_ERROR || command == POINTER_ERROR) return false;
    char *no_bin_commands[] = {"cd", "exit", "env", "unsetenv", "setenv", ARRAY_END};
    void (*commands[5]) (struct shell_datas *, char **) = {use_cd, exit_shell, use_env, use_unsetenv, use_setenv};

    for (int i = 0; no_bin_commands[i] != ARRAY_END; i++) {
        if (str_is_same(no_bin_commands[i], command[0])) {
            (*commands[i])(shell, command);
            return true;
        }
    }
    return false;
}

void use_command(struct shell_datas *shell, char **command)
{
    if (shell == POINTER_ERROR || command == POINTER_ERROR) return;
    if (commands_with_pipe(shell, command)) {
        return;
    }
    if (others_command(shell, command)) {
        return;
    }
    if (all_bin_commands(command, shell->env)) {
        return;
    }
    print_formatted("%s: command not found.\n", command[0]);
}