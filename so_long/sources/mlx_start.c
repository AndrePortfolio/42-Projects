/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:53:03 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/22 11:18:37 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_start(t_map *map)
{
	t_game	game;

	init_mlx_window(&game, map);
	init_game_images(&game);
	create_images(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_win, &game);
	mlx_loop(game.mlx);
}

void	init_mlx_window(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init();
	game->width = map->cols * SCALE;
	game->height = map->rows * SCALE;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	// mlx_get_screen_size();
}

void	init_game_images(t_game *game)
{
	init_walls(game);
	init_exit(game);
	init_player(game);
	init_collectibles(game);
	init_empty_space(game);
}
