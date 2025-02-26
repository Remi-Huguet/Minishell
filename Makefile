NAME = mysh

CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra

SRC = src/main.c						\
	 	src/shell_datas/*.c				\
	 	src/lib/*.c						\
	 	src/loop/*.c					\
	 	src/signals/*.c					\
	 	src/commands/*.c				\
	 	src/commands/cd/*.c				\
	 	src/commands/env/*.c

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all