NAME = push_swap.a

CC = cc

EXECUTABLE = push_swap

CFLAGS = -Wall -Wextra -Werror

FILES = make_push.c make_r_rotate.c make_rotate.c make_swap.c nodes_find.c nodes_init.c \
		push_swap.c stack_init.c stack_move.c stack_sort.c utils_errors.c utils_sort.c

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
