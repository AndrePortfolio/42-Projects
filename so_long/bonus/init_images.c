/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:47:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 13:22:00 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	init_player(t_game *game)
{
	int	i;

	i = 0;
	game->map->player.img = malloc(8 * sizeof(void *));
	if (!game->map->player.img)
	{
		free_player(game->map);
		free_map(game->map, "Memory allocation failed", 1);
	}
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcfront.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcfrontmv.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcback.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcbackmv.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcleft.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcleftmv.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcright.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[i++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcrightmv.xpm", &game->map->player.width,
			&game->map->player.height);
	while (--i >= 0)
	{
		if (!game->map->player.img[i])
			error_message("Player initialization failed");
	}
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
