#ifndef CD_H_
#define CD_H_

#include "../../shell_datas/shell_datas.h"

int array_get_len(char **array);
char *get_env_var(char **env, char *var);
int str_contain(char *str, char c);
int str_get_len(char *str);
void set_env_var(struct shell_datas *shell, char *var, char *value);

#endif /* !CD_H_ */