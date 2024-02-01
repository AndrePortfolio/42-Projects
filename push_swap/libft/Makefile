NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
RM = rm -rf

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
