NAME = mysh

CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra

SRCDIR = src src/shell_datas src/loop src/commands src/signals \
		src/commands/env src/commands/cd src/lib

SRC = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all