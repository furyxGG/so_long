NAME	=	so_long.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I ../minilibx-linux

SRCS	=	deneme.c

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