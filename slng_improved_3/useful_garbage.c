#include "so_long.h"

void	ternary_to_ord_if(t_data *data)
{
	if (data->animation_frame == 1)
		data->animation_frame = 2;
	else
		data->animation_frame = 1;
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_copy == NULL)
		return ;
	while (i < data->height)
	{
		free(data->map_copy[i]);
		i++;
	}
	free(data->map_copy);
	data->map_copy = NULL;
	if (data->mapp == NULL)
		return ;
	i = 0;
	while (i < data->height)
	{
		free(data->mapp[i]);
		i++;
	}
	free(data->mapp);
	data->mapp = NULL;
}

void	free_data(t_data *data)
{
	free_map(data);
	free(data);
}

void	file_error_msg(int fd, char *line, int flag)
{
	if (fd == -1 && flag == 1)
	{
		printf("Error\nNo such file or directory\n");
		exit(1);
	}
	else if (!line && flag == 2)
	{
		printf("Error\nEmpty file");
		exit(1);
	}
}
