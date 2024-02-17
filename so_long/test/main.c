/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:50:26 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/17 00:36:28 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (1);
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	print_collectable(t_game *game)
{
	int x = 50;
	int y;
	int	width = game->collectable.x;
	int	height;

	while (x > 0)
	{
		y = 50;
		height = game->collectable.y;
		while (y > 0)
		{
			int color = create_trgb(0, 0, 0, 100);
			mlx_pixel_put(game->mlx, game->win, width, height, color);
			height++;
			y--;
		}
		width++;
		x--;
	}
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
			mlx_pixel_put(game->mlx, game->win, width, height, color);
			height++;
			y--;
		}
		width++;
		x--;
	}
}

bool is_boarder_colletable(t_game *game)
{
	// This boarder is correct, however I would need to do a boarder for player too in order for this to work properly

	if((game->player.y >= game->collectable.y && game->player.y <= 100) && (game->player.x >= game->collectable.x && game->player.x <= 100))
		return (true);
	return (false);
}

char	is_boarder(t_game game)
{
	if(game.player.y <= -10)
		return ('W');
	if(game.player.x <= -10)
		return ('A');
	if(game.player.y >= (game.height - 110))
		return ('S');
	if(game.player.x >= (game.width - 110))
		return ('D');
	return (0);
}

int	player_move(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
	{
		if (is_boarder(*game) != 'W')
			game->player.y -= 30;
	}
	else if (keycode == A || keycode == LEFT)
	{
		if (is_boarder(*game) != 'A')
			game->player.x -= 30;
	}
	else if (keycode == S || keycode == DOWN)
	{
		if (is_boarder(*game) != 'S')
			game->player.y += 30;
	}
	else if (keycode == D || keycode == RIGHT)
	{
		if (is_boarder(*game) != 'D')
			game->player.x += 30;
	}
	print_background(game);
	print_player(game);
	if (!is_boarder_colletable(game))
		print_collectable(game);
	return (0);
}


int	main(void)
{
	t_game		game;

	game.mlx = mlx_init();
	game.width = 800;
	game.height = 500;
	game.win = mlx_new_window(game.mlx, game.width, game.height, "so_long");
	game.player.x = 350;
	game.player.y = 200;
	game.collectable.x = 50;
	game.collectable.y = 50;

	print_background(&game);
	print_player(&game);
	print_collectable(&game);
	mlx_hook(game.win, 2, 1L<<0, close_win, &game);
	mlx_key_hook(game.win, player_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
