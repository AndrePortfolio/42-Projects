/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:48:20 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/22 18:52:03 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		game->map->player.img[3], x * SCALE, y * SCALE);
	if (keycode == W || keycode == UP)
		put_player_image_aux(game, 2, x, y);
	else if (keycode == A || keycode == LEFT)
		put_player_image_aux(game, 4, x, y);
	else if (keycode == S || keycode == DOWN)
		put_player_image_aux(game, 0, x, y);
	else if (keycode == D || keycode == RIGHT)
		put_player_image_aux(game, 6, x, y);
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
