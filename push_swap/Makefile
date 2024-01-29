NAME = push_swap
CC = gcc
COMPRESS = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
FILES = make_push.c make_r_rotate.c make_rotate.c make_swap.c nodes_find.c nodes_init.c \
		push_swap.c stack_init.c stack_move.c stack_sort.c utils_errors.c utils_sort.c
LIBFT = libft/libft.a
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))
RM = rm -rf

# Test
NBRS = numbers.txt
READ_NBRS = $(shell cat $(NBRS))
NUM = $(if $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),$(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS)),5)
COMMAND= $(shell seq -999999 999999 | shuf -n $(NUM) > $(NBRS))
RUN = ./$(NAME) $(READ_NBRS)

# Colours
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "Creating library:    $(GREEN)$@$(RESET)"
	@echo "Creating objects:    $(GREEN)$@$(RESET)"
	@echo "Creating executable: $(RED)./$@$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: ../$(NAME)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C ./libft clean
	@echo "Cleaning objects:    $(GREEN)$(NAME)$(RESET)"
	@echo "Cleaning executable: $(RED)./$(NAME)$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "Cleaning library:    $(GREEN)$(NAME)$(RESET)"

re: fclean all

test: re
	@$(COMMAND)
	@echo "\n$(RED)./$(NAME)$(RESET)" $(READ_NBRS)
	@$(RUN)
	@printf "\n$(GREEN)Number of operations: $(RESET)%s\n" `$(RUN) | wc -l`
	@$(RM) $(NBRS)

valgrind: re
	@$(COMMAND)
	@echo "\n"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(READ_NBRS)
	$(RM) $(NBRS)

tester: re
	@echo "\n"
	@curl https://git.homegu.com/raw/hu8813/tester_push_swap/main/pstester.py | python3 -

%:
	@true

.PHONY: all clean fclean re test valgrind
