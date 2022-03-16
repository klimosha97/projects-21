NAME = fractol

SRC =	main.c				\
		fractols.c				\
		utils.c				\
		complex_nbr_utils.c	\
		hooks_keys.c		\
		init.c				\

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I fractol.h

W_FLAGS = -Wall -Werror -Wextra

LFLAGS = -Lminilibx-linux/ -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(OBJ): %.o: %.c
		gcc $(W_FLAGS) -Imlx -c -I libft/ $< -o $@

$(LIBFT):
	-@ make -C libft
	-@ make -C mlx

$(NAME): $(LIBFT) $(OBJ) fractol.h
	gcc $(W_FLAGS) $(OBJ) $(LIBFT) -I libft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	-@ rm -f $(NAME)
	-@ make -C libft fclean

re: fclean all

.PHONY:	all clean fclean re
