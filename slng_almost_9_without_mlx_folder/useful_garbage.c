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
	if (data->mp == NULL)
		return ;
	while (i < data->height)
	{
		free(data->mp[i]);
		i++;
	}
	free(data->mp);
	data->mp = NULL;
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
		ft_printf("Error : No such file or directory\n");
		exit(1);
	}
	else if (!line && flag == 2)
	{
		ft_printf("Error : Empty map\n");
		exit(1);
	}
}

void	error_msg(t_data *data)
{
	if (data->player_found)
	{
		ft_printf("Error: Multiple players (P) found!\n");
		exit(1);
	}
	if (data->exit_found)
	{
		ft_printf("Error: Multiple exits (E) found!\n");
		exit(1);
	}
}
