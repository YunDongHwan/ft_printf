NAME =					libftprintf.a

SRC_NAME =				ft_caculator.c\
						ft_getlength.c\
						ft_getlen_utils.c\
						ft_apply_op.c\
						ft_apply_numop.c\
						ft_checkvalid.c\
						ft_printf.c\
						ft_putflag.c\
						ft_put_utils.c\
						
						



OBJ_NAME =				$(SRC_NAME:.c=.o)

INC =					-I.

LIBFT =					./libft

LIBFT_A =				libft.a

CC =					gcc

CFLAGS =				-Wall -Wextra -Werror

AR =					ar rcs

$(NAME) : 				$(OBJ_NAME)
						make all -C $(LIBFT)
						cp $(LIBFT)/$(LIBFT_A) $(NAME)
						$(AR) $(NAME) $(OBJ_NAME)

%.o :					%.c
						$(CC) $(CFLAGS) $(INC) -c $< -o $@

all :					$(NAME)

clean :
						rm -f *.o
						make clean -C $(LIBFT)

fclean :				clean
						rm -f $(NAME)
						make fclean -C $(LIBFT)

re :
						make fclean all

.PHONY :				libft all clean fclean re
