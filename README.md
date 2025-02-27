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

## Run Unit Tests Dependencies
```bash
sudo apt install libcriterion-dev
```

## Run Unit Tests
```bash
make tests_run
```

## Options handled
- Execution of all binary in the differents paths they can be : "/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/"
- cd (not handled with ~)
- env, setenv, unsetenv
- exit to leave
- ctrl C / Z
- multi commands handled with ";"

## Options that are planed to be handled
- Redirections (">", ">>", "<", "<<") handlers
- Pipes ("|", "||") handlers

## C-Libs
For this project i use the some functions I've done myself that are usually used from the string.h / stdio.h / stdlib.h library (here in the c_libs folder). You can find the repo of the libs I've done are here : https://github.com/Remi-Huguet/C-Libs/