/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:45:53 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/02/09 23:11:54 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == UP)
		printf("Hello from %d!\n", UP);
	if (keycode == DOWN)
		printf("Hello from %d!\n", DOWN);
	if (keycode == RIGHT)
		printf("Hello from %d!\n", RIGHT);
	if (keycode == LEFT)
		printf("Hello from %d!\n", LEFT);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.width = 800;
	vars.height = 500;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Hello world!");

	// Quit
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);

	// Keypress
	mlx_key_hook(vars.win, key_hook, &vars);

	// Read images
	// char	*relative_path = "./player.png";

	// img.img = mlx_png_file_to_image(vars.mlx, relative_path, &vars.width, &vars.height);
	// if (img.img == NULL)
	// 	return (1);

	// Colour
	img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int	x = 0;
	int y;

	while (x < vars.width)
	{
		y = 0;
		while (y < vars.height)
		{
			int color = create_trgb(0, 0, 0, 100);
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
	int x_start = vars.width / 4;
	int x_end = vars.width - vars.width / 4;
	int y_start = vars.height / 4;
	int y_end = vars.height - vars.height / 4;

	x = x_start;
	while (x < x_end)
	{
		y = y_start;
		while (y < y_end)
		{
			int color = create_trgb(0, 0, 100, 0);
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
