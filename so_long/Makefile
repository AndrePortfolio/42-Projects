NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = sources
SRC_BONUS_DIR = sources_bonus

SRC = $(addprefix $(SRC_DIR)/,$(addsuffix .c, $(S)))

S = check_characters check_map close_program create_images init_images mlx_start \
	read_input so_long utils

SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/,$(addsuffix _bonus.c, $(B)))

B = check_characters check_map close_program create_images init_others mlx_start \
	read_input so_long utils create_images2 init_player

OBJ_DIR = objects
OBJ_BONUS_DIR = bonus_objects

LIBFT = libft/libft.a
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/,$(notdir $(SRC_BONUS:.c=.o)))
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

bonus: $(NAME)_bonus

$(NAME)_bonus: $(OBJ_BONUS_DIR) $(OBJ_BONUS) all
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)_bonus
	@echo "$(CYAN)make$(RESET)   bonus   $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(OBJ_BONUS_DIR):
	@mkdir -p $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C ./libft clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"
	@echo "$(ORANGE)$@$(RESET)  bonus   $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME)_bonus
	@$(MAKE) -C ./libft fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"
	@echo "$(RED)$@$(RESET) bonus   $(GREEN)[OK]$(RESET)"

re: fclean all bonus

v: re
	@echo "\n"
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map2.ber

v_mac: re
	@echo "\n"
	leaks -atExit -- ./$(NAME) maps/map2.ber

.PHONY: all clean fclean re bonus
