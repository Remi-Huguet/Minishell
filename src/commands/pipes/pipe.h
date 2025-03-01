#ifndef PIPE_H_
#define PIPE_H_

#include "../../shell_datas/shell_datas.h"

void single_pipe(struct shell_datas *shell, char **first_command, char **second_command);
void double_pipe(struct shell_datas *shell, char **first_command, char **second_command);
void use_command(struct shell_datas *shell, char **command);

#endif /* !PIPE_H_ */