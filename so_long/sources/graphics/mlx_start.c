/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:53:03 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/20 00:40:49 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		// free_map(game->map, "Game over", 1);
		exit (1);
	}
	return (0);
}

void	init_mlx_window(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->width = map->cols * SCALE + BOARDER * 2;
	game->height = map->rows * SCALE + BOARDER * 2;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	init_screen(t_game *game, t_img *img)
{
	img->img = mlx_new_image(game->mlx, game->width, game->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_pp, &img->l_lenght, &img->endian);
	game->load_img = img;
}

void	init_game_images(t_game *game)
{
	init_walls(game);
	init_exit(game);
	init_player(game);
	init_collectibles(game);
	init_empty_space(game);
}

// void	create_game_images(t_game *game, t_img *img)
// {

// }

void	mlx_start(t_map *map)
{
	t_game game;
	t_img	img;

	init_mlx_window(&game, map);
	init_screen(&game, &img);
	//init_game_images(&game);
	// create_game_images(&game, &img);
	mlx_hook(game.win, 2, 1L<<0, close_win, &game);
	mlx_loop(game.mlx);
}
