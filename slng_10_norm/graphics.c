/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:41:14 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/08/12 17:41:15 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
