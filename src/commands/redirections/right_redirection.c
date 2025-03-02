#include "macros.h"
#include "redirection.h"
#include "libs/print_lib.h"
#include "libs/string_lib.h"
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void right_redirection(struct shell_datas *shell, char **first_command, char **second_command, bool is_double)
{
    if (shell == POINTER_ERROR || first_command == POINTER_ERROR || second_command == POINTER_ERROR) return;
    int fd;
    pid_t pid = fork();

    if (pid == -1) {
        print_formatted("Redirection error: fork\n");
        return;
    }
    if (pid == 0) {
        if (is_double) {
            fd = open(second_command[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
        } else {
            fd = open(second_command[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
        if (fd == -1) {
            print_formatted("Redirection error: file create or open\n");
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        use_command(shell, first_command);
        exit(1);
    }
    waitpid(pid, NULL, 0);
}