SRC	= ft_printf.c \
	  ft_put_args.c \

OBJ	= $(patsubst %.c,%.o,$(SRC))

LIBFT	= libft/

L_COMP	= libft.a

HDR	= ft_printf.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

RM	= rm -f

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HDR)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)$(L_COMP) .
	@mv $(L_COMP) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT) clean

fclean:	clean
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re:	fclean all

.PHONY:	fclean clean re all
