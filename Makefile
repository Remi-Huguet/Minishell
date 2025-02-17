CFLAGS =	-W -Wall -Wextra

SRC =		src/main.c						\
			src/shell_datas/*.c				\
			src/lib/*.c						\
			src/loop/*.c					\
			src/signals/*.c					\
			src/commands/*.c				\
			src/commands/cd/*.c				\
			src/commands/env/*.c

NAME =		mysh

all:		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		re fclean clean all