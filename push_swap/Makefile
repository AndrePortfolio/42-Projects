NAME = push_swap.a

CC = cc

EXECUTABLE = push_swap

CFLAGS = -Wall -Wextra -Werror

FILES = errors.c push.c rev_rotate.c rotate.c sort_stack_utils.c utils.c\
		sort_stack.c stack_a_b.c stack_b_a.c stack_init.c swap.c utils_extra.c \
		main.c

OBJ_DIR = objects

LIBFT = libft/libft.a

MAIN = main.c

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
		@ar rcs $@ $(OBJ)
		@make -C ./libft
		@$(CC) $(CFLAGS) $(FILES) $(LIBFT) -o $(EXECUTABLE)
		@echo "Creating library:    $(GREEN)$@$(RESET)"
		@echo "Creating objects:    $(GREEN)$@$(RESET)"
		@echo "Creating executable: $(RED)./$(EXECUTABLE)$(RESET)"

$(OBJ_DIR)/%.o: ../push_swap/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
		@rm -rf $(EXECUTABLE) $(OBJ_DIR)
		@make clean -C ./libft
		@echo "Cleaning objects:    $(GREEN)$(NAME)$(RESET)"
		@echo "Cleaning executable: $(RED)./$(EXECUTABLE)$(RESET)"

fclean:
		@make fclean -C ./libft
		@rm -rf $(EXECUTABLE) $(OBJ_DIR) $(NAME)
		@echo "Cleaning objects:    $(GREEN)$(NAME)$(RESET)"
		@echo "Cleaning library:    $(GREEN)$(NAME)$(RESET)"
		@echo "Cleaning executable: $(RED)./$(EXECUTABLE)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
