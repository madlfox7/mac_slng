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
		printf("Error : No such file or directory\n");
		exit(1);
	}
	else if (!line && flag == 2)
	{
		printf("Error : Empty map\n");
		exit(1);
	}
}

void error_msg(t_data *data)
{
	 if (data->player_found)
    {
                    printf("Error: Multiple players (P) found!\n");
                    exit(1);
    }
if (data->exit_found)
                {
                    printf("Error: Multiple exits (E) found!\n");
                    exit(1);
                }

}


void oh_dear_norm(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->height)
    {
		x = 0;
        while (x < data->width)
        {
            if (data->mp[y][x] == 'P')
            {
                // if (data->player_found)
                // {
                //     printf("Error: Multiple players (P) found!\n");
                //     exit(1);
                // }
				error_msg(data);
                data->player_x_v = x;
                data->pl_y_v = y;
                data->player_found = 1;
            }
            else if (data->mp[y][x] == 'E')
            {
                // if (data->exit_found)
                // {
                //     printf("Error: Multiple exits (E) found!\n");
                //     exit(1);
                // }
				error_msg(data);
                data->exit_found = 1;
            }
			x++;
        }
		y++;
    }
}
