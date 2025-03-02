#ifndef REDIRECTION_H_
#define REDIRECTION_H_

#include "../../shell_datas/shell_datas.h"
#include <stdbool.h>

void use_command(struct shell_datas *shell, char **command);
void right_redirection(struct shell_datas *shell, char **first_command, char **second_command, bool is_double);
void left_single_redirection(struct shell_datas *shell, char **first_command, char **second_command);
void left_double_redirection(struct shell_datas *shell, char **first_command, char **second_command);

#endif /* !REDIRECTION_H_ */