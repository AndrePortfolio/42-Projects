NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c ft_help.c

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
