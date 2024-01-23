NAME = so_long.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = 

OBJ_DIR = objects

CYAN = \033[1;36m
RESET = \033[0m

OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "Creating library:    $(CYAN)$@$(RESET)"
	@echo "Creating objects:    $(CYAN)$@$(RESET)"

$(OBJ_DIR)/%.o: ../libft/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR) a.out
	@echo "Cleaning objects:    $(CYAN)$(NAME)$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "Cleaning library:    $(CYAN)$(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
