NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ./libft -I ./get_next_line -I ./ft_printf -I ./src -I ./minilibx-linux

PRINTF	=	ft_printf/libftprintf.a
LIBFT	=	libft/libft.a
GNL		=	get_next_line/gnl.a
SRC		=	src/so_long.a
MLX		=	minilibx-linux/libmlx.a

SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)

MLXFLAG	=	-Lminilibx-linux -lmlx -lX11 -lXext -lm

all:		$(NAME)

$(NAME):	$(OBJS) $(PRINTF) $(LIBFT) $(GNL) $(MLX) $(SRC)
	$(CC) $(CFLAGS) $(OBJS) $(SRC) $(PRINTF) $(LIBFT) $(GNL) $(MLX) $(MLXFLAG) -o $(NAME)

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