NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = sources
SRC = $(wildcard $(SRC_DIR)/*.c)
LIBFT = libft/libft.a
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
COMPRESS = ar rcs
RM = rm -rf

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C ./libft clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

test: re
	@echo "\n"
	< Makefile sort | uniq > test_1
	./pipex Makefile "sort" "uniq" test_2

v: re
	@echo "\n"
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) Makefile "sort" "uniq" test_1

v_mac: re
	@echo "\n"
	leaks -atExit -- ./$(NAME) Makefile "sort" "uniq" test_1

.PHONY: all clean fclean re
