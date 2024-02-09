/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:56:17 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/09 22:59:52 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	mlx_exit(t_mlx_start *par, char *message, int status)
{
	int	ctd;

	ctd = 0;
	while (ctd < 16)
		mlx_destroy_image(par->mlx, par->packman->img[ctd++].img);
	mlx_destroy_image(par->mlx, par->load_img->img);
	mlx_destroy_image(par->mlx, par->map->wall.img);
	mlx_destroy_image(par->mlx, par->map->floor.img);
	mlx_destroy_image(par->mlx, par->map->collectible.img);
	mlx_destroy_image(par->mlx, par->map->exit.img);
	mlx_destroy_image(par->mlx, par->map->boarder_vertical.img);
	mlx_destroy_image(par->mlx, par->map->boarder_horizontal.img);
	mlx_destroy_window(par->mlx, par->mlx_win);
	mlx_destroy_display(par->mlx);
	free(par->packman);
	free(par->mlx);
	freemap(par->map, message, status);
	return (0);
}

void	create_all(t_mlx_start *par, t_img *img)
{
	render_map(par, img);			// Pixel by pixel create the map image
	render_boarder(par, img);
	render_packman(par, img);
	put_screen(par, img);
}

void	mlx_initiazie_var(t_mlx_start *par, t_map *map)
{
	int	width;
	int	height;

	par->map = map;																	// Sets par-> map as map (which we already initialized)
	par->width = map->cols * SCALE + BORDER * 2;									// Defines window width based on the nbr of collons
	par->height = map->rows * SCALE + BORDER * 2;									// Defines window height based on the nbr of rows
	par->mlx = mlx_init();															// Initializes Minilibx
	mlx_get_screen_size(par->mlx, &width, &height);									// Returns window width and height values
	par->mlx_win = mlx_new_window(par->mlx, par->width, par->height, "So_Long");	// Creates a window named So_Long with the defined width and height
}

void	mlx_start(t_map *map)
{
	t_mlx_start	par;
	t_img		img;

	mlx_initiazie_var(&par, map);							// Initializes Minilibx and Window
	initialize_image(&par, &img, par.width, par.height);	// Initilizes Image to fit the whole window
	packman_init(&par);										// Initializes packman
	map_init(&par);											// Initializes map
	create_all(&par, &img);									//
	mlx_loop_hook(par.mlx, const_move, &par);
	mlx_hook(par.mlx_win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.mlx_win, 17, 1L << 17, mlx_exit, &par);
	mlx_loop(par.mlx);
}
