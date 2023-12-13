NAME = push_swap.a

CC = cc

EXECUTABLE = push_swap

CFLAGS = -Wall -Wextra -Werror

FILES = errors.c push.c rev_rotate.c rotate.c sort_stack_utils.c utils.c\
		sort_stack.c stack_a_b.c stack_b_a.c stack_init.c swap.c utils_extra.c \
		main.c

LIBFT = libft/libft.a

MAIN = main.c

all: $(NAME)

$(NAME): $(OBJS)
		@make -sC ./libft
		@$(CC) $(CFLAGS) $(FILES) $(LIBFT) -o $(EXECUTABLE)

clean:
		$(MAKE) clean -sC ./libft
		rm $(EXECUTABLE)

fclean: clean
		$(MAKE) fclean -sC ./libft

re: fclean $(NAME)

.PHONY: all clean fclean re
