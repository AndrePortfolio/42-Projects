/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:48:44 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/25 00:55:37 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_hook_aux(t_game *g, int keycode, int x, int y)
{
	if (g->map->map[g->map->player_y + y][g->map->player_x + x] == ENEMY)
	{
		if (keycode == W)
			put_player_image(g, W, g->map->player_x, g->map->player_y);
		else if (keycode == S)
			put_player_image(g, S, g->map->player_x, g->map->player_y);
		else if (keycode == A)
			put_player_image(g, A, g->map->player_x, g->map->player_y);
		else if (keycode == D)
			put_player_image(g, D, g->map->player_x, g->map->player_y);
		put_enemy_image(g, g->map->player_x + x, g->map->player_y + y);
	}
	else if (g->map->map[g->map->player_y + y][g->map->player_x + x] != WALL)
		move_player(g, keycode, g->map->player_x + x, g->map->player_y + y);
	else if (g->map->map[g->map->player_y + y][g->map->player_x + x] == WALL)
	{
		if (keycode == W)
			put_player_image(g, W, g->map->player_x, g->map->player_y);
		else if (keycode == S)
			put_player_image(g, S, g->map->player_x, g->map->player_y);
		else if (keycode == A)
			put_player_image(g, A, g->map->player_x, g->map->player_y);
		else if (keycode == D)
			put_player_image(g, D, g->map->player_x, g->map->player_y);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game, 0, ESC);
	else if (keycode == W || keycode == UP)
		key_hook_aux(game, W, 0, -1);
	else if (keycode == A || keycode == LEFT)
		key_hook_aux(game, A, -1, 0);
	else if (keycode == S || keycode == DOWN)
		key_hook_aux(game, S, 0, +1);
	else if (keycode == D || keycode == RIGHT)
		key_hook_aux(game, D, +1, 0);
	return (0);
}

void	move_player(t_game *game, int keycode, int x, int y)
{
	static int	exit_x = -1;
	static int	exit_y = -1;
	static int	exit_initialized = 0;

	if (game->map->map[y][x] == EXIT)
	{
		exit_x = x;
		exit_y = y;
		exit_initialized = 1;
		if (!find_collectible(game->map))
		{
			new_images(game, keycode, y, x);
			close_win(game, 0, WON);
		}
		else
			new_images(game, keycode, y, x);
	}
	else
	{
		new_images(game, keycode, y, x);
		if (exit_initialized)
			game->map->map[exit_y][exit_x] = EXIT;
	}
}

void	new_images(t_game *game, int keycode, int y, int x)
{
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
	create_images(game, keycode);
}

void	create_images(t_game *game, int keycode)
{
	int			color;
	char		*str;
	int			x;
	int			y;
	static int	i = 0;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			put_image(game, keycode, x, y);
			x++;
		}
		y++;
	}
	str = ft_itoa(++i);
	color = get_trgb(0, 0, 0, 0);
	mlx_string_put(game->mlx, game->win, 43, 15, color, str);
	free(str);
}
