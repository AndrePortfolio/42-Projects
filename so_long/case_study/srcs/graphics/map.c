/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:44 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 23:22:24 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_map(t_mlx_start *par, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (par->map->map[y])							// Iterate through collons
	{
		x = 0;
		while (par->map->map[y][x])						// Iterate through rows
		{
			render_map_condition(par, img, x, y);		// Displays the imgs of the state of the game
			x++;
		}
		y++;
	}
}

void	render_map_condition(t_mlx_start *par, t_img *img, int x, int y)
{
	if (par->map->map[y][x] == '1')													// If in this position there is a wall
	{
		create_img(img, par->map->wall, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	}
	else if (par->map->map[y][x] == '0')											// If in this position there is a floor
		create_img(img, par->map->floor, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	else if (par->map->map[y][x] == 'C')											// If in this position there is a collectible
		create_img(img, par->map->collectible, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	else if (par->map->map[y][x] == 'E' && par->map->collectibles_count == 0)		// If in this position there is an exit and no more collectibles
		create_img(img, par->map->exit, (x * SCALE) + BORDER, (y * SCALE)
			+ BORDER);
	else if (par->map->map[y][x] == 'E')											// If in this position there is an exit place a floor until
		create_img(img, par->map->floor, (x * SCALE) + BORDER, (y * SCALE)			// all collectibles are collected. So the player can't exit.
			+ BORDER);
}

void	render_boarder(t_mlx_start *par, t_img *img)
{
	int	x;
	int	y;

	(void)img;
	y = 0;
	while (y < par->map->rows)						// Iterate through rows
	{
		x = 0;
		while (x < par->map->cols)					// Iterate through collons
		{
			if (par->map->map[y][x] == '1')			// If it is a wall
			create_boarder(par, img, x, y);			//
			x++;
		}
		y++;
	}
}

void	create_boarder(t_mlx_start *par, t_img *img, int x, int y)
{
	if (x + 1 < par->map->cols && par->map->map[y][x + 1] == '1')					// Checks if it is a wall & doesnt pass the nbr of colons
	{
		if (y + 1 < par->map->rows && par->map->map[y + 1][x] == '1'
			&& par->map->map[y + 1][x + 1] == '1')
			pixel_fix(img, x, y);
		create_img(img, par->map->boarder_vertical, ((x + 1) * SCALE) + BORDER
			- 1, (y * SCALE) + BORDER + 1);
	}
	if (x - 1 >= 0 && par->map->map[y][x - 1] == '1')
		create_img(img, par->map->boarder_vertical, (x * SCALE) + BORDER, (y
				* SCALE) + BORDER + 1);
	if (y + 1 < par->map->rows && par->map->map[y + 1][x] == '1')
		create_img(img, par->map->boarder_horizontal, (x * SCALE) + BORDER + 1,
			((y + 1) * SCALE) + BORDER - 1);
	if (y - 1 >= 0 && par->map->map[y - 1][x] == '1')
		create_img(img, par->map->boarder_horizontal, (x * SCALE) + BORDER + 1,
			(y * SCALE) + BORDER);
}

void	pixel_fix(t_img *img, int x, int y)
{
	put_pixel(img, ((x + 1) * SCALE) + BORDER - 1, ((y + 1) * SCALE) + BORDER
		- 1, WALL_COLOR);
	put_pixel(img, ((x + 1) * SCALE) + BORDER, ((y + 1) * SCALE) + BORDER - 1,
		WALL_COLOR);
	put_pixel(img, ((x + 1) * SCALE) + BORDER - 1, ((y + 1) * SCALE) + BORDER,
		WALL_COLOR);
	put_pixel(img, ((x + 1) * SCALE) + BORDER, ((y + 1) * SCALE) + BORDER,
		WALL_COLOR);
}
