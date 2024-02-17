/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:18:41 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/17 00:09:20 by andrealbuqu      ###   ########.fr       */
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
	void			*img;
	char			*addr;
	int				endian;
	int				ln_lenght;
	int				bits_pp;
	int				width;
	int				height;
}				t_img;

typedef struct s_player
{
	int				x;
	int				y;
	t_img			img;
	char			dir;
	int				move;
	int				boarder;
}				t_player;

typedef struct s_collectable
{
	int				x;
	int				y;
	t_img			img;
	int				consumed;
}				t_collectable;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		player;
	t_collectable	collectable;
	int				width;
	int				height;
}				t_game;


#endif
