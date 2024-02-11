/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:18:41 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/10 15:32:30 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-mac/mlx.h"
//# include "../minilibx-linux/mlx.h"

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

// Linux
// # define ESC 65307
// # define RESTART 114
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
# define RESTART 114
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
	void *img;


}			t_img;

typedef struct s_map
{
	char	**map;
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	exit;
	t_img	boarder_vertical;
	t_img	boarder_horizontal;
	int		rows;
	int		cols;
	int		collectible_count;
}			t_map;

#endif
