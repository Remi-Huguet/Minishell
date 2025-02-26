#ifndef CD_H_
#define CD_H_

#include "../../shell_datas/shell_datas.h"

char *get_env_var(char **env, char *var);
void set_env_var(struct shell_datas *shell, char *var, char *value);

#endif /* !CD_H_ */