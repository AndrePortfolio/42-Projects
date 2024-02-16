/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:50:26 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/16 18:38:32 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_image(game->mlx, game->player.img.img);
		exit (1);
	}
	return (0);
}

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->ln_lenght + x * (data->bits_pp / 8));
// 	*(unsigned int*)dst = color;
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	print_background(t_game *game)
{
	int x = 0;
	int y;

	while (x < game->width)
	{
		y = 0;
		while (y < game->height)
		{
			int color = create_trgb(0, 0, 100, 100);
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
		x++;
	}
}

void	print_player(t_game *game)
{
	int x = 100;
	int y;
	int	width = game->player.x;
	int	height;

	while (x > 0)
	{
		y = 100;
		height = game->player.y;
		while (y > 0)
		{
			int color = create_trgb(0, 100, 0, 0);
			// get_pixel()

			mlx_pixel_put(game->mlx, game->win, width, height, color);
			height++;
			y--;
		}
		width++;
		x--;
	}
}

bool is_boarder(t_game game)
{
	if (game.player.x <= -10 || game.player.y <= -10
		|| game.player.x >= (game.width - 70) || game.player.y >= (game.height - 70))
		return (true);
	return (false);
}

int	player_move(int keycode, t_game *game)
{
	if (keycode == W)
	{
		if (!is_boarder(*game))
			game->player.y -= 30;
	}
	else if (keycode == A)
	{
		if (!is_boarder(*game))
			game->player.x -= 30;
	}
	else if (keycode == S)
		game->player.y += 30;
	else if (keycode == D)
		game->player.x += 30;
	print_background(game);
	print_player(game);
	return (0);
}


int	main(void)
{
	t_game		game;

	game.mlx = mlx_init();
	game.width = 800;
	game.height = 500;
	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");
	game.img.img = mlx_new_image(game.mlx, game.width, game.height);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_pp, &game.img.ln_lenght,
									&game.img.endian);

	game.player.x = 350;
	game.player.y = 200;
	game.player.img.img = mlx_new_image(game.mlx, 100, 100);
	game.player.img.addr = mlx_get_data_addr(game.player.img.img, &game.player.img.bits_pp,
											&game.player.img.ln_lenght, &game.player.img.ln_lenght);

	mlx_hook(game.win, 2, 1L<<0, close_win, &game);
	mlx_key_hook(game.win, player_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
