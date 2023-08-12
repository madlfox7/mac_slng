#include "so_long.h"

int	no_space(int player_count, int exit_count, int collectable, int empty_space)
{
	if (player_count != 1 || exit_count != 1
		|| collectable == 0 || empty_space == 0)
	{
		if (empty_space == 0)
			printf("Error: no space to move\n");
		return (1);
	}
	return (0);
}

int	counter(t_data *data, int *player_count, int *exit_count, int *collectable)
{
	int	empty_space;
	int	i;
	int	j;

	i = 0;
	empty_space = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->mp[i][j] == 'P')
				(*player_count)++;
			if (data->mp[i][j] == 'E')
				(*exit_count)++;
			if (data->mp[i][j] == 'C')
				(*collectable)++;
			if (data->mp[i][j] == '0')
				empty_space++;
			j++;
		}
		i++;
	}
	return (no_space(*player_count, *exit_count, *collectable, empty_space));
}

void	get_collect_count(t_data *data, int *collect_count)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->mp[y][x] == 'C')
				(*collect_count)++;
			x++;
		}
		y++;
	}
	if (!(*collect_count))
	{
		printf("No collectables found\n");
		exit(1);
	}
}

void	find_player_coordinates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->player_x = 0;
	data->player_y = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->mapp[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	win_case(t_data *data)
{
	int	i;
	int	j;
	int	coll_count;

	i = 0;
	coll_count = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->mapp[i][j] == 'C')
				coll_count++;
			j++;
		}
		i++;
	}
	if (coll_count == 0)
		return (1);
	return (0);
}
