NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = push_swap.c push_swap_utils.c main.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re