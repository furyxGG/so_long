NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ./includes/libft -I ./includes/get_next_line -I ./includes/ft_printf -I ./src -I ./includes/minilibx-linux

PRINTF	=	includes/ft_printf/libftprintf.a
LIBFT	=	includes/libft/libft.a
GNL		=	includes/get_next_line/gnl.a
SRC		=	src/so_long.a
MLX		=	includes/minilibx-linux/libmlx.a

SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)

MLXFLAG	=	-Lincludes/minilibx-linux -lmlx -lX11 -lXext -lm -lbsd

all:		$(NAME)

$(NAME):	$(OBJS) $(PRINTF) $(LIBFT) $(GNL) $(MLX) $(SRC)
	$(CC) $(CFLAGS) $(OBJS) $(SRC) $(PRINTF) $(GNL) $(LIBFT) $(MLX) $(MLXFLAG) -o $(NAME)

$(SRC):
	make -C $(dir $(SRC))

$(PRINTF):
	make -C $(dir $(PRINTF))

$(LIBFT):
	make -C $(dir $(LIBFT))

$(GNL):
	make -C $(dir $(GNL))

$(MLX):
	make -C $(dir $(MLX))

clean:
	rm -f $(OBJS)
	make -C $(dir $(SRC)) clean
	make -C $(dir $(PRINTF)) clean
	make -C $(dir $(LIBFT)) clean
	make -C $(dir $(GNL)) clean

fclean: clean
	rm -f $(NAME)
	make -C $(dir $(SRC)) fclean
	make -C $(dir $(PRINTF)) fclean
	make -C $(dir $(LIBFT)) fclean
	make -C $(dir $(GNL)) fclean

re:	fclean all

.PHONY: all clean fclean re