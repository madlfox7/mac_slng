#include "so_long.h"

void	image_load_checker(t_data *data)
{
	if (!data->frames[0][0] || !data->frames[0][1]
			|| !data->frames[1][0] || !data->frames[1][1]
			|| !data->frames[2][0] || !data->frames[2][1]
			|| !data->frames[3][0] || !data->frames[3][1])
	{
		printf("Error: Failed to load images.\n");
		exit(1);
	}
	if (!data->player || !data->wall || !data->free_space
		|| !data->collectable || !data->exit || !data->enemy)
	{
		printf("Error: Failed to load images.\n");
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

void	draw_tile(t_data *data, int i, int j, int frame_index)
{
	int	x;
	int	y;

	x = j * 64;
	y = i * 64;
	if (data->mapp[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
	else if (data->mapp[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
				data->frames[frame_index][data->animation_frame - 1], x, y);
	else if (data->mapp[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->free_space, x, y);
	else if (data->mapp[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collectable, x, y);
	else if (data->mapp[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
	else if (data->mapp[i][j] == 'T')
		mlx_put_image_to_window(data->mlx, data->win, data->enemy, x, y);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	frame_index;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			frame_index = 0;
			if (data->mapp[i][j] == 'P')
			{
				if (data->current_direction == BACK)
					frame_index = 1;
				else if (data->current_direction == LEFT)
					frame_index = 2;
				else if (data->current_direction == RIGHT)
					frame_index = 3;
			}
			draw_tile(data, i, j, frame_index);
			j++;
		}
		i++;
	}
}

void	ft_image(t_data *data)
{
	draw_map(data);
}

void	go_on_vacation(int keycode)
{
	if (keycode == 53)
	{
		printf("Techie is tired and decided to"
				"go on vacation, work will wait ✈️\n");
		exit(0);
	}
}

int	handle_key(int keycode, t_data *data)
{
	find_player_coordinates(data);
	go_on_vacation(keycode);
	if (keycode == 13 && data->mapp[data->player_x - 1][data->pl_y] != '1')
	{
		data->current_direction = FRONT;
		w_is_pressed(data);
	}
	else if (keycode == 1 && data->mapp[data->player_x + 1][data->pl_y] != '1')
	{
		data->current_direction = BACK;
		s_is_pressed(data);
	}
	else if (keycode == 0 && data->mapp[data->player_x][data->pl_y - 1] != '1')
	{
		data->current_direction = LEFT;
		a_is_pressed(data);
	}
	else if (keycode == 2 && data->mapp[data->player_x][data->pl_y + 1] != '1')
	{
		data->current_direction = RIGHT;
		d_is_pressed(data);
	}
	mlx_clear_window(data->mlx, data->win);
	ft_image(data);
	return (0);
}

void	graphics(t_data *data)
{
	data->win_h = (data->height) * 64;
	data->win_w = (data->width) * 64;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "so_long");
	load_image(data);
	data->animation_frame = 1;
	data->current_direction = FRONT;
	ft_image(data);
	mlx_hook(data->win, 2, 0, handle_key, data);
	mlx_hook(data->win, 17, 0, close_with_x, data);
	mlx_loop_hook(data->mlx, write_moves, data);
	mlx_loop(data->mlx);
}
