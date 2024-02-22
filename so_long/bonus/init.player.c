/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:50:26 by andre-da          #+#    #+#             */
/*   Updated: 2024/02/22 18:51:54 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_front_back_player(t_game *game)
{
	int	i;

	i = 0;
	game->map->player.img = malloc(8 * sizeof(void *));
	if (!game->map->player.img)
		free_map(game->map, "Memory allocation failed", 1);
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
	init_left_right_player(game, &i);
	while (--i >= 0)
	{
		if (!game->map->player.img[i])
			error_message("Player initialization failed");
	}
}

void	init_left_right_player(t_game *game, int *i)
{
	game->map->player.img[(*i)++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcleft.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[(*i)++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcleftmv.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[(*i)++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcright.xpm", &game->map->player.width,
			&game->map->player.height);
	game->map->player.img[(*i)++] = mlx_xpm_file_to_image(game->mlx,
			"./assets/npcrightmv.xpm", &game->map->player.width,
			&game->map->player.height);
}
