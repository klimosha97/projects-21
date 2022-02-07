NAME = pipex

NAME1 = pipex1

SRC0 =	main.c			\

SRC =	pipex_utils.c		\

SRC1 =	main_bonus.c		\
		gnl_pipex_bonus.c	\
		here_doc_bonus.c	\
		pipex_utils_bonus.c	\

OBJ0 = $(SRC0:.c=.o)
OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I pipex.h

W_FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ0): %.o: %.c
		-@gcc -c  -I libft/ $< -o $@

$(OBJ): %.o: %.c
		-@gcc -c  -I libft/ $< -o $@

$(OBJ1): %.o: %.c
		-@gcc -c  -I libft/ $< -o $@

$(LIBFT):
	-@ make -C libft

$(NAME): $(LIBFT) $(OBJ) $(OBJ0)
	-@ gcc $(W_FLAGS) $(OBJ0) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME1): $(LIBFT) $(OBJ) $(OBJ1)
	-@ gcc $(W_FLAGS) $(OBJ) $(OBJ1) $(LIBFT) -o pipex

clean:
	-@ rm -f $(OBJ) $(OBJ1) $(OBJ0)
	-@ make -C libft clean

fclean: clean
	-@ rm -f $(NAME) $(NAME1)
	-@ make -C libft fclean

bonus: pipex1

re: fclean all

.PHONY:		checker bonus all clean fclean re