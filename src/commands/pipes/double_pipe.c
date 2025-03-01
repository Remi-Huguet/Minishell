#include "pipe.h"
#include "macros.h"
#include "libs/print_lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void double_pipe(struct shell_datas *shell, char **first_command, char **second_command)
{
    if (shell == POINTER_ERROR || first_command == POINTER_ERROR || second_command == POINTER_ERROR) return;
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        print_formatted("Pipe error: fork second process\n");
        return;
    }
    if (pid == 0) {
        use_command(shell, first_command);
        exit(1);
    }
    waitpid(pid, &status, 0);
    if (WEXITSTATUS(status) != 0) {
        pid = fork();
        if (pid == 0) {
            use_command(shell, second_command);
            exit(1);
        }
        waitpid(pid, &status, 0);
    }
}