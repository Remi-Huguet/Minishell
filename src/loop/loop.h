#ifndef LOOP_H_
#define LOOP_H_

#include "../shell_datas/shell_datas.h"

void handle_control_c();
void init_shell_datas(struct shell_datas *shell, char **env);
void use_command(struct shell_datas *shell, char **command);

#endif /* !LOOP_H_ */