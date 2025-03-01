#include "pipe.h"
#include "macros.h"
#include "libs/print_lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void single_pipe(struct shell_datas *shell, char **first_command, char **second_command)
{
    if (shell == POINTER_ERROR || first_command == POINTER_ERROR || second_command == POINTER_ERROR) return;
    int pipefd[2];
    pid_t pid_first_process;
    pid_t pid_second_process;

    if (pipe(pipefd) == -1) {
        print_formatted("Pipe error: open pipe\n");
        return;
    }
    pid_first_process = fork();
    if (pid_first_process == -1) {
        print_formatted("Pipe error: fork first process\n");
        return;
    }
    if (pid_first_process == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        use_command(shell, first_command);
        exit(1);
    }
    pid_second_process = fork();
    if (pid_second_process == -1) {
        print_formatted("Pipe error: fork second process\n");
        return;
    }
    if (pid_second_process == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        use_command(shell, second_command);
        exit(1);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid_first_process, NULL, 0);
    waitpid(pid_second_process, NULL, 0);
}