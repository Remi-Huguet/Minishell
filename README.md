# Minishell
A shell in bash recreated.

## Description
No parameters needed to lauch the shell.
This program is like a linux shell in bash.
The idea of this project was make again a project i had to to in first year, but after learning more things (4 years later).

## Run
```bash
make
mysh
```

## Options handle
- Execution of all binary in the differents paths they can be : "/bin/", "/usr/bin/", "/usr/local/bin/", "/sbin/"
- cd is not handled with ~
- env, setenv, unsetenv
- exit to leave

## Options that are planed to be handled
- ";" handler, to use multiple commands
- Redirections (">", ">>", "<", "<<") handlers
- Pipes ("|", "||") handlers

## C string.h Lib
At src/lib, you have all the functions from the lib string.h i did, available at the repo : https://github.com/Remi-Huguet/C-String.h-Lib