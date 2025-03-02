#include "macros.h"
#include "redirection.h"
#include "libs/print_lib.h"
#include "libs/string_lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdio.h>

void left_double_redirection(struct shell_datas *shell, char **first_command, char **second_command)
{
    if (shell == POINTER_ERROR || first_command == POINTER_ERROR || second_command == POINTER_ERROR) return;
    pid_t pid;
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        print_formatted("Redirection error: pipe\n");
        return;
    }
    pid = fork();
    if (pid == -1) {
        print_formatted("Redirection error: fork\n");
        return;
    }
    if (pid == 0) {
        close(pipefd[0]);
        bool exit_loop = false;
        char *line = NULL;
        size_t size = 0;

        while (!exit_loop) {
            if (getline(&line, &size, stdin) == -1) {
                break;
            }
            int len = str_get_len(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = STR_END;
            }
            if (str_is_same(line, second_command[0])) {
                exit_loop = true;
            } else {
                write(pipefd[1], line, str_get_len(line));
            }
        }
        free(line);
        close(pipefd[1]);
        exit(0);
    }
    waitpid(pid, NULL, 0);
    close(pipefd[1]);
    pid = fork();
    if (pid == -1) {
        print_formatted("Redirection error: fork\n");
        return;
    }
    if (pid == 0) {
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        use_command(shell, first_command);
        exit(1);
    }
    close(pipefd[0]);
    waitpid(pid, NULL, 0);
}