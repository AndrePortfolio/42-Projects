/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:47:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/20 21:51:08 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_walls(t_game *game)
{
	game->map->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &game->map->wall.width, &game->map->wall.height);
	if (!game->map->wall.img)
		error_message("Wall initialization failed");
	game->map->wall.addr = mlx_get_data_addr(game->map->wall.img, &game->map->wall.bits_pp, &game->map->wall.l_lenght, &game->map->wall.endian);
}

void	init_exit(t_game *game)
{
	game->map->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm", &game->map->exit.width, &game->map->exit.height);
	if (!game->map->exit.img)
		error_message("Exit initialization failed");
	game->map->exit.addr = mlx_get_data_addr(game->map->exit.img, &game->map->exit.bits_pp, &game->map->exit.l_lenght, &game->map->exit.endian);
}

void	init_player(t_game *game)
{
	game->map->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/snake.xpm/head_down.xpm", &game->map->player.width, &game->map->player.height);
	if (!game->map->player.img)
		error_message("Player initialization failed");
	game->map->player.addr = mlx_get_data_addr(game->map->player.img, &game->map->player.bits_pp, &game->map->player.l_lenght, &game->map->player.endian);
}

void	init_collectibles(t_game *game)
{
	game->map->collectible.img = mlx_xpm_file_to_image(game->mlx, "./assets/apple.xpm", &game->map->collectible.width, &game->map->collectible.height);
	if (!game->map->collectible.img)
		error_message("Collectible initialization failed");
	game->map->collectible.addr = mlx_get_data_addr(game->map->collectible.img, &game->map->collectible.bits_pp, &game->map->collectible.l_lenght, &game->map->collectible.endian);
}

void	init_empty_space(t_game *game)
{
	game->map->space.img = mlx_xpm_file_to_image(game->mlx, "./assets/space.xpm", &game->map->space.width, &game->map->space.height);
	if (!game->map->space.img)
		error_message("Empty space initialization failed");
	game->map->space.addr = mlx_get_data_addr(game->map->space.img, &game->map->space.bits_pp, &game->map->space.l_lenght, &game->map->space.endian);
}
