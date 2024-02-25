/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:48:20 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/25 00:55:27 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_image_aux(t_game *game, int img, int x, int y)
{
	static int	i = 0;

	if (i % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->player.img[img], x * SCALE, y * SCALE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->player.img[img + 1], x * SCALE, y * SCALE);
	i++;
}

void	put_player_image(t_game *game, int keycode, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->map->player.img[1], x * SCALE, y * SCALE);
	if (keycode == W || keycode == UP)
		put_player_image_aux(game, 2, x, y);
	else if (keycode == A || keycode == LEFT)
		put_player_image_aux(game, 4, x, y);
	else if (keycode == S || keycode == DOWN)
		put_player_image_aux(game, 0, x, y);
	else if (keycode == D || keycode == RIGHT)
		put_player_image_aux(game, 6, x, y);
}

void	put_enemy_image(t_game *game, int x, int y)
{
	static int	i = 0;

	if (i % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->enemy.img[1], x * SCALE, y * SCALE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->enemy.img[0], x * SCALE, y * SCALE);
	i++;
}

void	put_image(t_game *game, int keycode, int x, int y)
{
	if (game->map->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->wall.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == PLAYER)
		put_player_image(game, keycode, x, y);
	else if (game->map->map[y][x] == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->space.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->collectible.img, x * SCALE, y * SCALE);
	else if (game->map->map[y][x] == ENEMY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->map->enemy.img[0], x * SCALE, y * SCALE);
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

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
