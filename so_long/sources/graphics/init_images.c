/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:47:38 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/20 00:40:41 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_walls(t_game *game)
{
	game->img->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &game->img->wall.width, &game->img->wall.height);
	if (!game->img->wall.img)
		error_message("Wall initialization failed");
	game->img->wall.addr = mlx_get_data_addr(game->img->wall.img, &game->img->wall.bits_pp, &game->img->wall.l_lenght, &game->img->wall.endian);
}

void	init_exit(t_game *game)
{
	game->img->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm", &game->img->exit.width, &game->img->exit.height);
	if (!game->img->exit.img)
		error_message("Exit initialization failed");
	game->img->exit.addr = mlx_get_data_addr(game->img->exit.img, &game->img->exit.bits_pp, &game->img->exit.l_lenght, &game->img->exit.endian);
}

void	init_player(t_game *game)
{
	game->img->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/head_down.xpm", &game->img->player.width, &game->img->player.height);
	if (!game->img->player.img)
		error_message("Player initialization failed");
	game->img->player.addr = mlx_get_data_addr(game->img->player.img, &game->img->player.bits_pp, &game->img->player.l_lenght, &game->img->player.endian);
}

void	init_collectibles(t_game *game)
{
	game->img->collectible.img = mlx_xpm_file_to_image(game->mlx, "./assets/apple.xpm", &game->img->collectible.width, &game->img->collectible.height);
	if (!game->img->collectible.img)
		error_message("Collectible initialization failed");
	game->img->collectible.addr = mlx_get_data_addr(game->img->collectible.img, &game->img->collectible.bits_pp, &game->img->collectible.l_lenght, &game->img->collectible.endian);
}

void	init_empty_space(t_game *game)
{
	game->img->space.img = mlx_xpm_file_to_image(game->mlx, "./assets/space.xpm", &game->img->space.width, &game->img->space.height);
	if (!game->img->space.img)
		error_message("Empty space initialization failed");
	game->img->space.addr = mlx_get_data_addr(game->img->space.img, &game->img->space.bits_pp, &game->img->space.l_lenght, &game->img->space.endian);
}
