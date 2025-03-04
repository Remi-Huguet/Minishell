# Minishell
A shell in Bash recreated.

## Description
No parameters are needed to launch the shell.
This program works like a Linux Bash shell.
The idea of this project was to refactor a project I did in my first year, but with improvements based on what I have learned since then, along with some unit tests.

## Install Dependencies
```bash
sudo apt install gcc
```

## Run
```bash
make
mysh
```

## Options handled
- Execution of all binary in the differents paths they can be in : "/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/"
- cd (not handled with ~)
- env, setenv, unsetenv
- exit to leave
- ctrl C / Z
- multiple commands handled with ";"
- redirections (">", ">>", "<", "<<") handled (only in format : "'command' 'redirection_sign' 'command'")
- pipes (">", ">>", "<", "<<") handled (only in format : "'command' 'pipe_sign' 'command'")

# Options that can be handled in the future:
- Multiple pipes or redirections, or combinations of pipes and redirections.

## C-Libs
For this project, I used some functions that I wrote myself, which are typically found in the string.h, stdio.h, and stdlib.h libraries (located in the c_libs folder). 
You can find the repository for the libraries I created here: https://github.com/Remi-Huguet/C-Libs/