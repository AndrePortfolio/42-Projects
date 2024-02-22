/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:48:44 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/22 01:41:09 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *g)
{
	if (key == ESC)
		close_win(g, 0, ESC);
	else if (key == W || key == UP)
	{
		if (g->map->map[g->map->player_y - 1][g->map->player_x] != WALL)
			move_player(g, key, g->map->player_y - 1, g->map->player_x);
	}
	else if (key == A || key == LEFT)
	{
		if (g->map->map[g->map->player_y][g->map->player_x - 1] != WALL)
			move_player(g, key, g->map->player_y, g->map->player_x - 1);
	}
	else if (key == S || key == DOWN)
	{
		if (g->map->map[g->map->player_y + 1][g->map->player_x] != WALL)
			move_player(g, key, g->map->player_y + 1, g->map->player_x);
	}
	else if (key == D || key == RIGHT)
	{
		if (g->map->map[g->map->player_y][g->map->player_x + 1] != WALL)
			move_player(g, key, g->map->player_y, g->map->player_x + 1);
	}
	return (0);
}

void	move_player(t_game *game, int keycode, int y, int x)
{
	if (game->map->map[y][x] == EXIT)
	{
		if (!find_collectible(game->map))
		{
			new_images(game, keycode, y, x);
			close_win(game, 0, WON);
		}
	}
	else
		new_images(game, keycode, y, x);
}

void	new_images(t_game *game, int keycode, int y, int x)
{
	static int	i = 0;

	game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
	game->map->map[y][x] = PLAYER;
	if (keycode == W || keycode == UP)
		game->map->player_y--;
	else if (keycode == A || keycode == LEFT)
		game->map->player_x--;
	else if (keycode == S || keycode == DOWN)
		game->map->player_y++;
	else if (keycode == D || keycode == RIGHT)
		game->map->player_x++;
	ft_printf("Move: %d\n", ++i);
	create_images(game);
}

void	create_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			put_image(game, x, y);
			x++;
		}
		y++;
	}
}

void	put_image(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->wall.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->player.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->space.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->collectible.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == EXIT)
	{
		if (!find_collectible(game->map))
			mlx_put_image_to_window(game->mlx, game->win,
				game->map->exit.img, x * SCALE, y * SCALE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->map->space.img, x * SCALE, y * SCALE);
	}
}



