NAME = libsc.a

CC_LIB = ar rcs
CC = gcc
RM = rm -rf

CFLAGS = -W -Wall -Wextra -Werror -Iinclude

SRCDIR = src/string_lib src/memory_lib src/print_lib

SRC = $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC_LIB) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all