#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "../shell_datas/shell_datas.h"

void check_signal(int wstatus);
void use_cd(struct shell_datas *shell, char **command);
void use_env(struct shell_datas *shell, char **command);
void use_setenv(struct shell_datas *shell, char **command);
void use_unsetenv(struct shell_datas *shell, char **command);

#endif /* !COMMANDS_H_ */