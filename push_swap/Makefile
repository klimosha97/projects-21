NAME = push_swap

NAME1= checker

SRC0 =	main.c			\

SRC =	check1.c		\
		clear.c			\
		decision.c		\
		insructions.c	\
		instructions2.c	\
		main_sort.c		\
		sorting.c		\
		gnl4check.c		\
		instructions3.c	\

SRC1 =	checker.c		\

OBJ0 = $(SRC0:.c=.o)
OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I push_swap.h

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
	-@ gcc $(W_FLAGS) $(OBJ) $(OBJ1) $(LIBFT) -o $(NAME1)

clean:
	-@ rm -f $(OBJ) $(OBJ1) $(OBJ0)
	-@ make -C libft clean

fclean: clean
	-@ rm -f $(NAME) $(NAME1)
	-@ make -C libft fclean

bonus: checker

re: fclean all

.PHONY:		checker bonus all clean fclean re