NAME = so_long
CC = cc
CFLAGS = -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
MLX_DIR = minilibx-mac#Mac
MLX_LIB = $(MLX_DIR)/libmlx.a#Mac
MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/libmlx#Mac
MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit#Mac
#MLX_DIR = minilibx-linux#Linux
#MLX_LIB = $(MLX_DIR)/libmlx_Linux.a#Linux
#MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/linux#Linux
#MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz#Linux

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
