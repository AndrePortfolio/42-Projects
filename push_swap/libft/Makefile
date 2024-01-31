NAME = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c ft_itoa.c \
			ft_strjoin.c ft_split.c ft_substr.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_printf.c \
			ft_printf_utils.c get_next_line.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c ft_atol.c ft_free_a_array.c
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))
RM = rm -rf

# Colours
CYAN = \033[1;36m
ORANGE = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $@.a $(OBJ)

$(OBJ_DIR)/%.o: ../$(NAME)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(ORANGE)$@$(RESET)  $(NAME)     $(GREEN)[OK]$(RESET)"

fclean:
	@$(RM) $(NAME).a
	@echo "$(RED)$@$(RESET) $(NAME)     $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
