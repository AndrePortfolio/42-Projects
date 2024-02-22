/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_others_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:47:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 20:59:18 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_walls(t_game *game)
{
	game->map->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/bush.xpm",
			&game->map->wall.width, &game->map->wall.height);
	if (!game->map->wall.img)
		error_message("Wall initialization failed");
}

void	init_exit(t_game *game)
{
	game->map->exit.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/imgexit.xpm",
			&game->map->exit.width, &game->map->exit.height);
	if (!game->map->exit.img)
		error_message("Exit initialization failed");
}

void	init_collectibles(t_game *game)
{
	game->map->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/poke.xpm", &game->map->collectible.width,
			&game->map->collectible.height);
	if (!game->map->collectible.img)
		error_message("Collectible initialization failed");
}

void	init_empty_space(t_game *game)
{
	game->map->space.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/fond.xpm", &game->map->space.width,
			&game->map->space.height);
	if (!game->map->space.img)
		error_message("Empty space initialization failed");
}
