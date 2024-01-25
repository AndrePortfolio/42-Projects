TARGET = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
MLX_DIR = ./minilibx
MINILIBX = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz
FILES =
OBJ_DIR = objects
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m
OBJ = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

all: $(TARGET)

$(TARGET): $(MLX) $(OBJ) $(LIBFT)
		@ar rcs $@ $(OBJ)
		@make -C ./libft
		@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBFT) $(MINILIBX)
		@echo "Creating library:    $(GREEN)$@.a$(RESET)"
		@echo "Creating objects:    $(GREEN)$@.a$(RESET)"
		@echo "Creating executable: $(RED)./$@$(RESET)"

$(OBJ_DIR)/%.o: ../so_long/%.c
	@mkdir -p $@
	@$(CC) $(CFLAGS) -Iheaders/ -ILibft/ -Iminilibx-linux -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C ./libft
		@echo "Cleaning objects:    $(GREEN)$(TARGET)$(RESET)"
		@echo "Cleaning executable: $(RED)./$(TARGET)$(RESET)"

fclean:
		@make fclean -C ./libft
		@rm -rf $(TARGET)
		@echo "Cleaning objects:    $(GREEN)$(TARGET).a$(RESET)"
		@echo "Cleaning library:    $(GREEN)$(TARGET).a$(RESET)"
		@echo "Cleaning executable: $(RED)./$(TARGET)$(RESET)"

re: fclean all

test: re
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET) test_map_big.ber

run: all
	./$(TARGET) includes/maps/test.ber

.PHONY: all clean fclean re test run
