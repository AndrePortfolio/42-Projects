TARGET = push_swap
CC = gcc
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
RUN = ./push_swap $(READ_NBRS)

# Colours
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(TARGET)

$(TARGET): $(OBJ_DIR) $(OBJ)
	@ar rcs $@ $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(FILES) $(LIBFT) -o $(TARGET)
	@echo "Creating library:    $(GREEN)$@.a$(RESET)"
	@echo "Creating objects:    $(GREEN)$@.a$(RESET)"
	@echo "Creating executable: $(RED)./$@$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: ../$(TARGET)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C ./libft
	@echo "Cleaning objects:    $(GREEN)$(TARGET).a$(RESET)"
	@echo "Cleaning executable: $(RED)./$(TARGET).a$(RESET)"

fclean:
	@make fclean -C ./libft
	@$(RM) $(TARGET)
	@echo "Cleaning objects:    $(GREEN)$(TARGET).a$(RESET)"
	@echo "Cleaning library:    $(GREEN)$(TARGET).a$(RESET)"
	@echo "Cleaning executable: $(RED)./$(TARGET)$(RESET)"

re: fclean all

test: re
	@$(COMMAND)
	@echo "\n$(RED)./$(TARGET)$(RESET)" $(READ_NBRS)
	@$(RUN)
	@printf "$(GREEN)Number of operations: $(RESET)%s\n" `$(RUN) | wc -l`
	$(RM) $(NBRS)

valgrind: re
	@$(COMMAND)
	@echo "\n"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) $(READ_NBRS)
	$(RM) $(NBRS)

tester: re
	@echo "\n"
	@curl https://git.homegu.com/raw/hu8813/tester_push_swap/main/pstester.py | python3 -

%:
	@true

.PHONY: all clean fclean re test valgrind
