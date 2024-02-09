/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:36:37 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 22:17:51 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	find_start(t_mlx_start *par)
{
	int	x;
	int	y;

	y = 0;
	while (y < par->map->rows)							// Iterates through the rows
	{
		x = 0;
		while (x < par->map->cols)						// Iterates through the rows
		{
			if (par->map->map[y][x] == 'P')				// If it finds the Player
			{
				par->packman->x = x * SCALE + BORDER;	// Gets the horizontal position of packman
				par->packman->y = y * SCALE + BORDER;	// Gets the vertical position of packman
				par->map->map[y][x] = '0';				// Player already found, position no longer required
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_addr(t_mlx_start *par)
{
	par->packman->img[0].addr = mlx_get_data_addr(par->packman->img[0].img,		// Get the address of img, bpp, line lenght and endian
			&par->packman->img[0].bits_per_pixel,
			&par->packman->img[0].line_length,
			&par->packman->img[0].endian);
}

void	render_packman(t_mlx_start *par, t_img *img)
{
	create_img(img, par->packman->img[0], par->packman->x, par->packman->y);
}
