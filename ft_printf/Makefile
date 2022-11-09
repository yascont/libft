CC=cc
NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
SRC=main.c puts.c putx.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ): $(SRC) ft_printf.h
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re