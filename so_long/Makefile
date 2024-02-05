NAME = so_long
CC = cc
CFLAGS = -g
SRC = $(wildcard *.c)
LIBFT = libft/libft.a
OBJ_DIR = objects
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
COMPRESS = ar rcs
RM = rm -rf

# Mac
#MLX_DIR = minilibx-mac
#MLX_LIB = $(MLX_DIR)/libmlx.a
#MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/libmlx
#MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Linux
MLX_DIR = minilibx-linux
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

$(OBJ_DIR)/%.o: %.c
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

.PHONY: all clean fclean re
