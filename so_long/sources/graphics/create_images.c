/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:48:44 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/21 18:55:47 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_game_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
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
				mlx_put_image_to_window(game->mlx, game->win,
					game->map->exit.img, x * SCALE, y * SCALE);
			x++;
		}
		y++;
	}
}
