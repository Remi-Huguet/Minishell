# Minishell
A shell in bash recreated.

## Description
No parameters needed to lauch the shell.
This program is like a linux shell in bash.
The idea of this project was to refacto a project i had to to in first year, but after learning more things. With some unit tests.

## Run
```bash
make
mysh
```

## Options handled
- Execution of all binary in the differents paths they can be : "/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/"
- cd (not handled with ~)
- env, setenv, unsetenv
- exit to leave
- ctrl C / Z
- multiple commands handled with ";"
- redirections (">", ">>", "<", "<<") handled (only in format : "'command' 'redirection_sign' 'command'")
- pipes (">", ">>", "<", "<<") handled (only in format : "'command' 'pipe_sign' 'command'")

# Options that can be handled in the future
- multiple pipes or redirections, or pipes and redirections combinaisons

## C-Libs
For this project i use the some functions I've done myself that are usually used from the string.h / stdio.h / stdlib.h library (here in the c_libs folder). You can find the repo of the libs I've done are here : https://github.com/Remi-Huguet/C-Libs/