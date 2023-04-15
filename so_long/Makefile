
NAME:=	so_long
SRC:= 	game.c game_init.c map_read.c map_check.c check_path.c map_render.c player_render.c keys.c\
		main_loop.c move_character.c free_all.c lib/libft/ft_strncmp.c lib/libft/ft_strlcpy.c\
		
 BSRC:=	game_bonus.c game_init_bonus.c map_read_bonus.c map_check_bonus.c check_path_bonus.c\
  		map_render_bonus.c player_render_bonus.c keys_bonus.c\
		main_loop_bonus.c move_character_bonus.c lib/libft/ft_strncmp.c lib/libft/ft_strlcpy.c\
		textures_bonus.c enemy_bonus.c enemy_animation_bonus.c end_game.c free_all.c lib/libft/ft_itoa.c\

OBJ:=	$(SRC:.c=.o)
BOBJ:=	$(BSRC:%.c=bonus/%.o)

FLAGS:=	-Wall -Werror -Wextra
#FLAGS+= -g3 -fsanitize=address

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/get_next_line
	make re -C lib/ft_printf
	$(CC) $(FLAGS) -lglfw -L "$(shell brew --prefix glfw)/lib/" -o $(NAME) $(OBJ) lib/get_next_line/get_next_line.a lib/ft_printf/ft_printf.a lib/MLX42/libmlx42.a
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@

bonus: $(BOBJ)
	make -C lib/get_next_line
	make -C lib/ft_printf
	$(CC) $(FLAGS) -lglfw -L "$(shell brew --prefix glfw)/lib/" -o bonus/bonus $(BOBJ) lib/get_next_line/get_next_line.a lib/ft_printf/ft_printf.a bonus/lib/MLX42/libmlx42.a
bonus/%.o: bonus/%.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ) $(BOBJ)
fclean: clean
	rm -f so_long bonus/bonus
re: fclean all