#ifndef SHELL_DATAS_H_
#define SHELL_DATAS_H_

#include <stdbool.h>

struct shell_datas {
    char **prompt;
    char **env;
    bool exit;
};

#endif /* !SHELL_DATAS_H_ */