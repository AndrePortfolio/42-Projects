/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:41 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/03/08 15:22:08 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-mac/mlx.h"
// # include "../minilibx/minilibx-linux/mlx.h"

# define PLAYER 80
# define EXIT 69
# define COLLECTIBLE 67
# define WALL 49
# define EMPTY 48
# define WON 87
# define VISITED 86
# define SCALE 50

// Linux
// # define ESC 65307
// # define W 119
// # define A 97
// # define S 115
// # define D 100
// # define UP 65362
// # define LEFT 65361
// # define RIGHT 65363
// # define DOWN 65364

// Mac
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define RIGHT 124
# define DOWN 125

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			collect_nbr;
	int			exit_nbr;
	int			player_x;
	int			player_y;
	t_img		wall;
	t_img		player;
	t_img		space;
	t_img		collectible;
	t_img		exit;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*load_img;
	t_map		*map;
	int			width;
	int			height;
}				t_game;

// Read input
void	read_input(t_map *map, int argc, char **argv);
void	read_map(t_map *map, int fd, int rows);
void	validate_map(t_map *map);
char	**copy_map(t_map *map, char **original, int rows);

// Check map
bool	is_rectangular(t_map	*map);
bool	around_walls(t_map	*map);
void	player_access(t_map *map, char **visited, int x, int y);

// Check characters
bool	check_characters(t_map *map, int exit, int collect, int space);
int		count_player(t_map *map, char chr, int y, int x);
void	count_others(char *chr, int *exit, int *collect, int *space);

// Mlx start
void	mlx_start(t_map *map);
void	init_mlx_window(t_game *game, t_map *map);
void	init_game_images(t_game *game);

// Init images
void	init_walls(t_game *game);
void	init_exit(t_game *game);
void	init_player(t_game *game);
void	init_collectibles(t_game *game);
void	init_empty_space(t_game *game);

// Create images
int		key_hook(int key, t_game *g);
void	move_player(t_game *game, int keycode, int y, int x);
void	new_images(t_game *game, int keycode, int y, int x);
void	create_images(t_game *game);
void	put_image(t_game *game, int x, int y);

// Utils
bool	find_collectible(t_map *map);
bool	is_ber(char *str);

// Close Program
int		close_win(t_game *game, int status, int exit);
void	free_map(t_map *map, char *str, int status);
void	error_message(char *str);

#endif
