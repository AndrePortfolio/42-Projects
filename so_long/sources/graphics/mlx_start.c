/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:53:03 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/21 22:23:14 by andre-da         ###   ########.fr       */
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

bool	find_collectible(t_map *map)
{
	int	i = 0;
	int	j;

	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	key_hook(int keycode, t_game *game)
{
	static int i = 0;

	if (keycode == ESC)
		close_win(game, 0);
	else if (keycode == W || keycode == UP)
	{
		if (game->map->map[game->map->player_y - 1][game->map->player_x] != WALL)
		{
			if (game->map->map[game->map->player_y - 1][game->map->player_x] == EXIT)
			{
				if (!find_collectible(game->map))
				{
					game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
					game->map->map[game->map->player_y - 1][game->map->player_x] = PLAYER;
					game->map->player_y--;
					create_game_images(game);
					close_win(game, 0);
				}
			}
			else if (game->map->map[game->map->player_y - 1][game->map->player_x] != EXIT)
			{
				game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
				game->map->map[game->map->player_y - 1][game->map->player_x] = PLAYER;
				game->map->player_y--;
				create_game_images(game);
				ft_printf("Move: %d\n", ++i);
			}
		}
	}
	else if (keycode == A || keycode == LEFT)
	{
		if (game->map->map[game->map->player_y][game->map->player_x - 1] != WALL)
		{
			if (game->map->map[game->map->player_y][game->map->player_x - 1] == EXIT)
			{
				if (!find_collectible(game->map))
				{
					game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
					game->map->map[game->map->player_y][game->map->player_x - 1] = PLAYER;
					game->map->player_x--;
					create_game_images(game);
					close_win(game, 0);
				}
			}
			else if (game->map->map[game->map->player_y][game->map->player_x - 1] != EXIT)
			{
				game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
				game->map->map[game->map->player_y][game->map->player_x - 1] = PLAYER;
				game->map->player_x--;
				create_game_images(game);
				ft_printf("Move: %d\n", ++i);
			}
		}
	}
	else if (keycode == S || keycode == DOWN)
	{
		if (game->map->map[game->map->player_y + 1][game->map->player_x] != WALL)
		{
			if (game->map->map[game->map->player_y + 1][game->map->player_x] == EXIT)
			{
				if (!find_collectible(game->map))
				{
					game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
					game->map->map[game->map->player_y + 1][game->map->player_x] = PLAYER;
					game->map->player_y++;
					create_game_images(game);
					close_win(game, 0);
				}
			}
			else if (game->map->map[game->map->player_y + 1][game->map->player_x] != EXIT)
			{
				game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
				game->map->map[game->map->player_y + 1][game->map->player_x] = PLAYER;
				game->map->player_y++;
				create_game_images(game);
				ft_printf("Move: %d\n", ++i);
			}
		}
	}
	else if (keycode == D || keycode == RIGHT)
	{
		if (game->map->map[game->map->player_y][game->map->player_x + 1] != WALL)
		{
			if (game->map->map[game->map->player_y][game->map->player_x + 1] == EXIT)
			{
				if (!find_collectible(game->map))
				{
					game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
					game->map->map[game->map->player_y][game->map->player_x + 1] = PLAYER;
					game->map->player_x++;
					create_game_images(game);
					close_win(game, 0);
				}
			}
			else if (game->map->map[game->map->player_y][game->map->player_x + 1] != EXIT)
			{
				game->map->map[game->map->player_y][game->map->player_x] = EMPTY;
				game->map->map[game->map->player_y][game->map->player_x + 1] = PLAYER;
				game->map->player_x++;
				create_game_images(game);
				ft_printf("Move: %d\n", ++i);
			}
		}
	}
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
