NAME	=	so_long.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ../includes/minilibx-linux -I ../includes/ft_printf -I ../includes/libft -I ../includes/get_next_line

SRCS	=	read_map.c \
			check_map.c \
			init_map.c \
			check_path.c \
			init_player.c \
			init_game.c \
			init_mlx.c \
			init_wall.c \
			keys.c \
			player_animation.c \
			main_animation.c \
			init_enemy.c \
			enemy_animation.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re