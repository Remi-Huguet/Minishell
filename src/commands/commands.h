#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "../shell_datas/shell_datas.h"

void check_signal(int wstatus);
void use_cd(struct shell_datas *shell);
void use_env(struct shell_datas *shell);
void use_setenv(struct shell_datas *shell);
void use_unsetenv(struct shell_datas *shell);
int str_get_len(char *str);

#endif /* !COMMANDS_H_ */