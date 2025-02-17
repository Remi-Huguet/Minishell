#ifndef ENV_H_
#define ENV_H_

#include "../../shell_datas/shell_datas.h"

int str_get_len(char *str);
int array_get_len(char **array);
int get_env_var_index(char **env, char *var);

#endif /* !ENV_H_ */