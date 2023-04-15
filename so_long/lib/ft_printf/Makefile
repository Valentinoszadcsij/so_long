NAME=	ft_printf.a
SRC= 	ft_printf.c length.c specifier.c write_char.c write_nbr.c write_pointer.c\
		write_string.c write_unbr.c write_hex.c\

OBJ=	$(SRC:.c=.o)

FLAGS=	-Wall -Werror -Wextra

CC= cc

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f ft_printf.a
re: fclean all