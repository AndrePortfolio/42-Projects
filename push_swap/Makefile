NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = errors.c push_swap.c push.c rev_rotate.c rotate.c sort_stack_utils.c \
		sort_stack.c stack_a_b.c stack_b_a.c stack_init.c swap.c utils_extra.c \
		utils.c

OBJS = $(FILES:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
		@make -sC ./libft
		ar rcs $(NAME) $(OBJS) $(LIBFT)

clean:
		$(MAKE) clean -sC ./libft
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -sC ./libft
		rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
