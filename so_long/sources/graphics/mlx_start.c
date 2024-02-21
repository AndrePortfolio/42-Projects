/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:53:03 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/21 19:48:10 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_game *game, int status)
{
	mlx_destroy_image(game->mlx, game->map->wall.img);
	mlx_destroy_image(game->mlx, game->map->collectible.img);
	mlx_destroy_image(game->mlx, game->map->player.img);
	mlx_destroy_image(game->mlx, game->map->space.img);
	mlx_destroy_image(game->mlx, game->map->exit.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, "Game over", status);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_win(game, 0);
	// else if (keycode == W || keycode == UP)
	// 	//
	// else if (keycode == A || keycode == LEFT)
	// 	//
	// else if (keycode == S || keycode == DOWN)
	// 	//
	// else if (keycode == D || keycode == RIGHT)
	// 	//
	return (0);
}

void	init_mlx_window(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init();
	game->width = map->cols * SCALE;
	game->height = map->rows * SCALE;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	init_game_images(t_game *game)
{
	init_walls(game);
	init_exit(game);
	init_player(game);
	init_collectibles(game);
	init_empty_space(game);
}

void	mlx_start(t_map *map)
{
	t_game	game;

	init_mlx_window(&game, map);
	init_game_images(&game);
	create_game_images(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_win, &game);
	mlx_loop(game.mlx);
}
