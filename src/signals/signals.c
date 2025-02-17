#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void check_signal(int wstatus)
{
    if (WIFSIGNALED(wstatus)) {
        int signal_code = WTERMSIG(wstatus);

        printf("Procces terminated by signal %d (%s)\n", signal_code, strsignal(signal_code));
    }
}

void handle_control_c()
{
    signal(SIGINT, SIG_IGN);
}