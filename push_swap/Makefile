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
COMMAND_MAC = $(shell jot -r -n $(NUM) -999999 999999 > $(NBRS))
RUN = ./$(NAME) $(READ_NBRS)
CHECKER = ./checker_linux $(READ_NBRS)
CHECKER_MAC = ./checker_mac $(READ_NBRS)

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   libft     $(GREEN)[OK]$(RESET)"
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: ../$(NAME)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C ./libft clean
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

test: re
	@$(COMMAND)
	@echo "\n$(RED)./$(NAME)$(RESET)" $(READ_NBRS)
	@$(RUN)
	@printf "\n$(CYAN)Number of operations: $(RESET)%s\n" `$(RUN) | wc -l`
	@printf "$(GREEN)Checker: $(RESET)"
	@$(RUN) | $(CHECKER)
	@$(RM) $(NBRS)

test_mac: re
	@$(COMMAND_MAC)
	@echo "\n$(RED)./$(NAME)$(RESET)" $(READ_NBRS)
	@$(RUN)
	@printf "\n$(CYAN)Number of operations: $(RESET)%s\n" `$(RUN) | wc -l`
	@printf "$(GREEN)Checker: $(RESET)"
	@$(RUN) | $(CHECKER_MAC)
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

.PHONY: all clean fclean re test test_mac valgrind tester
