#include "so_long.h"

void	check_lines_len(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
}

void	init_vals(char **res, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->mp[i][j] = res[i][j];
			data->mapp[i][j] = res[i][j];
			j++;
		}
		i++;
	}
}

void	free_map_j(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(data->mapp[j]);
		j++;
	}
}

void	alloc_mp(t_data *data)
{
	int	i;

	i = 0;
	data->mapp = (char **)malloc(data->height * sizeof(char *));
	if (data->mapp == NULL)
	{
		ft_printf("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (i < data->height)
	{
		data->mapp[i] = (char *)malloc(data->width * sizeof(char));
		if (data->mapp[i] == NULL)
		{
			ft_printf("Memory allocation failed");
			free_map_j(data, i);
			free(data->mapp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	allocate_map(t_data *data)
{
	int	i;

	i = 0;
	data->mp = (char **)malloc(data->height * sizeof(char *));
	if (data->mp == NULL)
	{
		ft_printf("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (i < data->height)
	{
		data->mp[i] = (char *)malloc(data->width * sizeof(char));
		if (data->mp[i] == NULL)
		{
			ft_printf("Memory allocation failed");
			free_map_j(data, i);
			free(data->mp);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	alloc_mp(data);
}
