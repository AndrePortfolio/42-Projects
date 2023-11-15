NAME = get_next_line.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = get_next_line.c get_next_line_utils.c

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
