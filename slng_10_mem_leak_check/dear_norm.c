/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dear_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <ksudzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:43:18 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/08/12 18:54:20 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	oh_dear_norm(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->mp[y][x] == 'P')
			{
				error_msg(data);
				data->player_x_v = x;
				data->pl_y_v = y;
				data->player_found = 1;
			}
			else if (data->mp[y][x] == 'E')
			{
				error_msg(data);
				data->exit_found = 1;
			}
			x++;
		}
		y++;
	}
}

void	initialize_map_validation_data(t_map_val_data *map_data)
{
	map_data->player_x = -1;
	map_data->pl_y = -1;
	map_data->player_found = 0;
	map_data->exit_found = 0;
	map_data->collect_count = 0;
	map_data->exit_is_accessible = 0;
}

void	map_error_msg(t_map_val_data map_data, int flag)
{
	if (map_data.player_found && flag == 1)
	{
		ft_printf("Error: Multiple players (P) found!\n");
		system("leaks so_long");
		exit (1);
	}
	if (map_data.exit_found && flag == 2)
	{
		ft_printf("Error: Multiple exits (E) found!\n");
		system("leaks so_long");
		exit (1);
	}
	if (flag == 3)
	{
		if (!map_data.player_found)
		{
			ft_printf("Error: Player (P) not found!\n");
			system("leaks so_long");
			exit (1);
		}
		if (!map_data.exit_found)
		{
			ft_printf("Error: Exit (E) not found!\n");
			system("leaks so_long");
			exit (1);
		}
	}
}

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C' || c == 'T')
		return (1);
	return (0);
}
