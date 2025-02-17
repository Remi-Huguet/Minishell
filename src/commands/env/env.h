#ifndef ENV_H_
#define ENV_H_

#include "../../shell_datas/shell_datas.h"

void use_env(struct shell_datas *shell);
void use_setenv(struct shell_datas *shell);
void use_unsetenv(struct shell_datas *shell);

#endif /* !ENV_H_ */