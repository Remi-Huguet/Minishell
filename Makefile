NAME = mysh

CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra -I./c_libs/include
LFLAGS = -L./c_libs -lsc

SRCDIR = src src/shell_datas src/loop src/commands src/signals \
		src/commands/env src/commands/cd src/commands/pipes 	\
		src/commands/redirections

SRC = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C c_libs
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C c_libs clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C c_libs fclean

re: fclean all

.PHONY: re fclean clean all