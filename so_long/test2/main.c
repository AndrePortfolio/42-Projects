/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:50:26 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/21 13:52:10 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_screen(t_game *game, int color)
{
	int	x = 0;
	int	y;

	while (x < game->width)
	{
		y = 0;
		while (y < game->height)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
		x++;
	}
}

int	color(int keycode, t_game *game)
{
	if (keycode == R)
		color_screen(game, create_trgb(0, 255, 0, 0));
	else if (keycode == G)
		color_screen(game, create_trgb(0, 0, 255, 0));
	else if (keycode == B)
		color_screen(game, create_trgb(0, 0, 0, 255));
	else if (keycode == ESC)
		close_win(game);
	return (0);
}

int	main(void)
{
	t_game		game;

	game.mlx = mlx_init();
	game.width = 800;
	game.height = 500;
	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");

	mlx_hook(game.win, 2, 1L<<0, color, &game);
	mlx_loop(game.mlx);
	return (0);
}
