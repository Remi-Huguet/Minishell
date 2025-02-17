#ifndef SHELL_DATAS_H_
#define SHELL_DATAS_H_

#include <stdbool.h>

struct shell_datas {
    char **prompt;
    char **env;
    bool exit;
};

void init_shell_datas(struct shell_datas *shell, char **env);

#endif /* !SHELL_DATAS_H_ */