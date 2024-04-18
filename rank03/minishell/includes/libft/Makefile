NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
RM = rm -rf
SRC = $(addsuffix .c, $(S))
S = ft_atoi ft_atol ft_bzero ft_calloc ft_freematrix ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_lstadd_back \
	ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize ft_memcpy ft_memmove ft_memset ft_printf \
	ft_printf_utils ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strcmp ft_strdup ft_strequ ft_striteri \
	ft_strjoin ft_strjoin_free ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower \
	ft_toupper get_next_line

# Colours
CYAN = \033[1;36m
ORANGE = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$(CYAN)make$(RESET)   libft     $(GREEN)[OK]$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(ORANGE)$@$(RESET)  libft     $(GREEN)[OK]$(RESET)"

fclean:
	@$(RM) $(NAME)
	@echo "$(RED)$@$(RESET) libft     $(GREEN)[OK]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
