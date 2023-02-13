
NAME:=	get_next_line.a
SRC:= 	get_next_line.c  get_next_line_utils.c\
		
# BSRC:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
# 		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ:=	$(SRC:.c=.o)

# BOBJ:=	$(BSRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
# bonus: $(BOBJ)
# 	ar -r $(NAME) $^
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f get_next_line.a
re: fclean all