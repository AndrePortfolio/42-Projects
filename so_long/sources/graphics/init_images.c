/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:47:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/21 19:42:40 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_walls(t_game *game)
{
	game->map->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/bush.xpm",
			&game->map->wall.width, &game->map->wall.height);
	if (!game->map->wall.img)
		error_message("Wall initialization failed");
	ft_printf("\nwall width:  %d\n", game->map->wall.width);
	ft_printf("wall height: %d\n", game->map->wall.height);
}

void	init_exit(t_game *game)
{
	game->map->exit.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/imgexit.xpm",
			&game->map->exit.width, &game->map->exit.height);
	if (!game->map->exit.img)
		error_message("Exit initialization failed");
	ft_printf("\nexit width:  %d\n", game->map->exit.width);
	ft_printf("exit height: %d\n", game->map->exit.height);
}

void	init_player(t_game *game)
{
	game->map->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/npc.xpm", &game->map->player.width,
			&game->map->player.height);
	if (!game->map->player.img)
		error_message("Player initialization failed");
	ft_printf("\nplayer width:  %d\n", game->map->player.width);
	ft_printf("player height: %d\n", game->map->player.height);
}

void	init_collectibles(t_game *game)
{
	game->map->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/poke.xpm", &game->map->collectible.width,
			&game->map->collectible.height);
	if (!game->map->collectible.img)
		error_message("Collectible initialization failed");
	ft_printf("\ncollect width:  %d\n", game->map->collectible.width);
	ft_printf("collect height: %d\n", game->map->collectible.height);
}

void	init_empty_space(t_game *game)
{
	game->map->space.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/fond.xpm", &game->map->space.width,
			&game->map->space.height);
	if (!game->map->space.img)
		error_message("Empty space initialization failed");
	ft_printf("\nspace width:  %d\n", game->map->space.width);
	ft_printf("space height: %d\n", game->map->space.height);
}
