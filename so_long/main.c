#include "so_long.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		exit (0);
	}
	return (0);
}

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

int handle_resize(t_vars *vars)
{
	printf("Window resized!\n");
	return (0);
}

int	main(void)
{
	t_data	img;
	t_vars	vars;
	int width = 800;
	int	height = 500;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_hook(vars.win, 12, 1L<<15, handle_resize, &vars);
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int	white = 0x00FFFFFF;
	int red = 0x00FF0000;
	int	x = 100;
	int	y = 100;

	while (x < 200)
	{
		while (y < 200)
		{
			int color = create_trgb(0, 0, 0, 100);
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
