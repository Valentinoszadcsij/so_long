
NAME:=	so_long.out
SRC:= 	game.c game_init.c map_read.c map_check.c check_path.c lib/libft/ft_strncmp.c\
		
# BSRC:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
# 		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ:=	$(SRC:.c=.o)

# BOBJ:=	$(BSRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
# FLAGS+= -g3 -fsanitize=address

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/get_next_line
	$(CC) $(FLAGS) -lglfw -L /Users/voszadcs/homebrew/Cellar/glfw/3.3.8/lib -o $(NAME) $(OBJ) lib/get_next_line/get_next_line.a lib/MLX42/libmlx42.a
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
# bonus: $(BOBJ)
# 	ar -r $(NAME) $^
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f so_long.out
re: fclean all