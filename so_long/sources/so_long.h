/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:18:41 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/18 21:41:33 by andrealbuqu      ###   ########.fr       */
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

typedef struct s_xy
{
	int		x;
	int		y;
}			t_xy;

typedef struct s_map
{
	char	**map;
	int		collect_nbr;
	int		rows;
	int		cols;
	t_xy	player;
}			t_map;

void	error_message(char *str);
void	free_map(t_map *map, char *str, int status);
void	read_input(t_map *map, int argc, char **argv);
void	read_map(t_map *map, int fd, int rows);
bool	is_ber(char *str);
void	free_map(t_map *map, char *str, int status);
bool	is_rectangular(t_map	*map);
bool	around_walls(t_map	*map);
bool	check_characters(t_map *map, int exit, int collect, int space);

#endif
