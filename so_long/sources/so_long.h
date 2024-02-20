/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:12:41 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/20 00:10:27 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-mac/mlx.h"
//# include "../minilibx/minilibx-linux/mlx.h"

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
# define VISITED 'V'
# define SCALE 50
# define BOARDER 50

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
	char		*addr;
	int			bits_pp;
	int			endian;
	int			l_lenght;
	int			width;
	int			height;
}				t_img;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			collect_nbr;
	int			exit_nbr;
	t_xy		player;
}				t_map;

typedef struct s_character
{
	t_img		wall;
	t_img		space;
	t_img		collectible;
	t_img		exit;
	t_img		player;
}				t_character;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*load_img;
	t_character	*img;
	t_map		*map;
	t_player	*player;
	int			width;
	int			height;
}				t_game;

// PARSING

// Read input
void	read_map(t_map *map, int fd, int rows);
bool	is_ber(char *str);
char	**copy_map(t_map *map, char **original, int rows, int cols);
void	validate_map(t_map *map);
void	read_input(t_map *map, int argc, char **argv);

// Check map
bool	is_rectangular(t_map	*map);
bool	around_walls(t_map	*map);
bool	check_characters(t_map *map, int exit, int collect, int space);
int		count(t_map *map, char chr, int i, int j);
void	player_access(t_map *map, char **visited, int x, int y);

// Close program
void	error_message(char *str);
void	free_map(t_map *map, char *str, int status);

// GRAPHICS

void	mlx_start(t_map *map);
void	init_walls(t_game *game);
void	init_exit(t_game *game);
void	init_player(t_game *game);
void	init_collectibles(t_game *game);
void	init_empty_space(t_game *game);

#endif