CC = gcc
CFLAGS = -g
NAME = so_long
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_INC = -I$(MLX_DIR) -I$(MLX_DIR)/linux
MLX_LINK = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

