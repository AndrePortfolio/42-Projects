/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:53:03 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/20 22:17:07 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(t_game *game, int status)
{
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
	game->width = map->cols * SCALE + BOARDER * 2;
	game->height = map->rows * SCALE + BOARDER * 2;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
}

void	init_screen(t_game *game, t_img *img)
{
	img->img = mlx_new_image(game->mlx, game->width, game->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_pp, &img->l_lenght, &img->endian);
	game->load_img = img;
	free(img->img);
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
	t_img	img;

	init_mlx_window(&game, map);
	init_screen(&game, &img);
	init_game_images(&game);
	//create_game_images(&game, &img);
	//put_screen(&game, &img);
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_hook(game.win, 17, 1L<<17, close_win, &game);
	mlx_loop(game.mlx);
}
