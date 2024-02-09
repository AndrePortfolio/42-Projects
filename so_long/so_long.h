/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:18:41 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/09 14:13:51 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-mac/mlx.h"
//# include "minilibx-linux/mlx.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define RESET	"\033[0m"

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

#endif
