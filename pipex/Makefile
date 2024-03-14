NAME = pipex
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g
CC = cc
COMPRESS = ar rcs
RM = rm -rf

SRC_DIR = sources
OBJ_DIR = objects
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))

SRC_BONUS_DIR = sources_bonus
OBJ_BONUS_DIR = bonus_objects
SRC_BONUS = $(wildcard $(SRC_BONUS_DIR)/*.c)
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/,$(notdir $(SRC_BONUS:.c=.o)))

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

bonus: $(NAME)_bonus

$(NAME)_bonus: $(OBJ_BONUS_DIR) $(OBJ_BONUS) all
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)_bonus
	@echo "$(CYAN)make$(RESET)   bonus $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR):
	@mkdir -p $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C ./libft clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"
	@echo "$(ORANGE)$@$(RESET)  bonus $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME)_bonus test_1 test_2
	@$(MAKE) -C ./libft fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"
	@echo "$(RED)$@$(RESET) bonus $(GREEN)[OK]$(RESET)"

re: fclean all bonus

test1: re
	@echo "\n"
	< Makefile sort | uniq > test_1
	./pipex Makefile "sort" "uniq" test_2

test2: re
	@echo "\n"
	./pipex Makefile "ls -l" "wc -l" test_1
	< Makefile ls -l | wc -l > test_2

v1: re
	@echo "\n"
	valgrind -s --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./$(NAME) Makefile sort uniq test_1

v2: re
	@echo "\n"
	valgrind -s --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./$(NAME) Makefile "ls -l" "wc -l" test_1

env: re
	@echo "\n"
	env -i ./pipex Makefile sort uniq test_1

v_mac: re
	@echo "\n"
	leaks -atExit -- ./$(NAME) Makefile "sort" "uniq" test_1

.PHONY: all clean fclean re bonus $(NAME)_bonus
