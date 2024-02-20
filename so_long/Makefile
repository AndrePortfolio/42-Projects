NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR1 = sources
SRC_DIR2 = sources/graphics
SRC = $(wildcard $(SRC_DIR1)/*.c) $(wildcard $(SRC_DIR2)/*.c)
LIBFT = libft/libft.a
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
COMPRESS = ar rcs
RM = rm -rf

# Mac
#MLX_DIR = minilibx/minilibx-mac
#MLX_LIB = $(MLX_DIR)/libmlx.a
#MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/libmlx
#MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Linux
MLX_DIR = minilibx/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR1)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR2)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C ./libft clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

v: re
	@echo "\n"
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map2.ber

v_mac: re
	@echo "\n"
	leaks -atExit -- ./$(NAME) maps/map2.ber

.PHONY: all clean fclean re
