#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "../shell_datas/shell_datas.h"

#include <stdbool.h>

void check_signal(int wstatus);
void use_cd(struct shell_datas *shell, char **command);
void use_env(struct shell_datas *shell, char **command);
void use_setenv(struct shell_datas *shell, char **command);
void use_unsetenv(struct shell_datas *shell, char **command);
bool commands_with_pipe(struct shell_datas *shell, char **commands);

#endif /* !COMMANDS_H_ */