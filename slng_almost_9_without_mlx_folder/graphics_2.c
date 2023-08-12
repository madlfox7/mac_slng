#include "so_long.h"

void	go_on_vacation(int keycode)
{
	if (keycode == 53)
	{
		ft_printf("Techie is tired and decided to "
			" go on vacation, work will wait ✈️\n");
		exit(0);
	}
}

void	image_load_checker(t_data *data)
{
	if (!data->frames[0][0] || !data->frames[0][1]
			|| !data->frames[1][0] || !data->frames[1][1]
			|| !data->frames[2][0] || !data->frames[2][1]
			|| !data->frames[3][0] || !data->frames[3][1])
	{
		ft_printf("Error: Failed to load images.\n");
		exit(1);
	}
	if (!data->player || !data->wall || !data->free_space
		|| !data->collectable || !data->exit || !data->enemy)
	{
		ft_printf("Error: Failed to load images.\n");
		exit(1);
	}
}

void	load_image(t_data *data)
{
	int	h;
	int	w;

	h = (data->win_h) / 64;
	w = (data->win_w) / 64;
	data->frames[0][0] = mlx_xpm_file_to_image(data->mlx, "xpm/f1.xpm", &h, &w);
	data->frames[0][1] = mlx_xpm_file_to_image(data->mlx, "xpm/f2.xpm", &h, &w);
	data->frames[1][0] = mlx_xpm_file_to_image(data->mlx, "xpm/b1.xpm", &h, &w);
	data->frames[1][1] = mlx_xpm_file_to_image(data->mlx, "xpm/b2.xpm", &h, &w);
	data->frames[2][0] = mlx_xpm_file_to_image(data->mlx, "xpm/l1.xpm", &h, &w);
	data->frames[2][1] = mlx_xpm_file_to_image(data->mlx, "xpm/l2.xpm", &h, &w);
	data->frames[3][0] = mlx_xpm_file_to_image(data->mlx, "xpm/r1.xpm", &h, &w);
	data->frames[3][1] = mlx_xpm_file_to_image(data->mlx, "xpm/r2.xpm", &h, &w);
	data->player = mlx_xpm_file_to_image(data->mlx, "xpm/pl.xpm", &h, &w);
	data->wall = mlx_xpm_file_to_image(data->mlx, "xpm/wall_1.xpm", &h, &w);
	data->free_space = mlx_xpm_file_to_image(data->mlx, "xpm/fl.xpm", &h, &w);
	data->collectable = mlx_xpm_file_to_image(data->mlx, "xpm/c.xpm", &h, &w);
	data->exit = mlx_xpm_file_to_image(data->mlx, "xpm/exit.xpm", &h, &w);
	data->enemy = mlx_xpm_file_to_image(data->mlx, "xpm/enemy.xpm", &h, &w);
	image_load_checker(data);
	data->moves = 0;
}
