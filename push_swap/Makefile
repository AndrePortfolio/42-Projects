TARGET = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FILES = make_push.c make_r_rotate.c make_rotate.c make_swap.c nodes_find.c nodes_init.c \
		push_swap.c stack_init.c stack_move.c stack_sort.c utils_errors.c utils_sort.c
LIBFT = libft/libft.a
OBJ_DIR = objects
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m
OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJ_DIR) $(OBJ)
		@ar rcs $@ $(OBJ)
		@make -C ./libft
		@$(CC) $(CFLAGS) $(FILES) $(LIBFT) -o $(TARGET)
		@echo "Creating library:    $(GREEN)$@.a$(RESET)"
		@echo "Creating objects:    $(GREEN)$@.a$(RESET)"
		@echo "Creating executable: $(RED)./$@$(RESET)"

$(OBJ_DIR)/%.o: ../push_swap/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C ./libft
		@echo "Cleaning objects:    $(GREEN)$(TARGET).a$(RESET)"
		@echo "Cleaning executable: $(RED)./$(TARGET).a$(RESET)"

fclean:
		@make fclean -C ./libft
		@rm -rf $(TARGET)
		@echo "Cleaning objects:    $(GREEN)$(TARGET).a$(RESET)"
		@echo "Cleaning library:    $(GREEN)$(TARGET).a$(RESET)"
		@echo "Cleaning executable: $(RED)./$(TARGET)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
