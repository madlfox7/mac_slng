#include "so_long.h"

int	close_with_x(t_data *data)
{
	ft_printf("Techie decided to go on a vacation. Work will wait ✈️\n");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	w_is_pressed(t_data *data)
{
	if (data->mapp[data->player_x - 1][data->pl_y] == 'T')
	{
		ft_printf("Oh no, Techie caught a bug. GAME OVER\n");
		exit(0);
	}
	if (data->mapp[data->player_x - 1][data->pl_y] == 'E')
	{
		if (win_case(data))
		{
			ft_printf("Good job! You helped Techie, "
				"he will never forget it ◡̈\n");
			exit(0);
		}
		return ;
	}
	if (data->mapp[data->player_x - 1][data->pl_y] != '1')
	{
		data->mapp[data->player_x - 1][data->pl_y] = 'P';
		data->mapp[data->player_x][data->pl_y] = '0';
		data->moves++;
		write_moves(data);
	}
	ternary_to_ord_if(data);
	data->current_direction = BACK;
}

void	s_is_pressed(t_data *data)
{
	if (data->mapp[data->player_x + 1][data->pl_y] == 'T')
	{
		ft_printf("Oh no, Techie caught a bug. GAME OVER\n");
		exit(0);
	}
	if (data->mapp[data->player_x + 1][data->pl_y] == 'E')
	{
		if (win_case(data))
		{
			ft_printf("Cheers! You did it ◡̈ \nTechie "
				"is grateful for your help and wishes you a bug-free "
				"coding experience 💻\n");
			exit(0);
		}
		return ;
	}
	if (data->mapp[data->player_x + 1][data->pl_y] != '1')
	{
		data->mapp[data->player_x + 1][data->pl_y] = 'P';
		data->mapp[data->player_x][data->pl_y] = '0';
		data->moves++;
		write_moves(data);
	}
	ternary_to_ord_if(data);
	data->current_direction = FRONT;
}

void	a_is_pressed(t_data *data)
{
	if (data->mapp[data->player_x][data->pl_y - 1] == 'T')
	{
		ft_printf("Oh no, Techie caught a bug. GAME OVER\n");
		exit(0);
	}
	if (data->mapp[data->player_x][data->pl_y - 1] == 'E')
	{
		if (win_case(data))
		{
			ft_printf("Cheers! You did it)\nTechie is grateful and "
				"wishing u a bug-free coding experience💻\n");
			exit(0);
		}
		return ;
	}
	if (data->mapp[data->player_x][data->pl_y - 1] != '1')
	{
		data->mapp[data->player_x][data->pl_y - 1] = 'P';
		data->mapp[data->player_x][data->pl_y] = '0';
		data->moves++;
		write_moves(data);
	}
	ternary_to_ord_if(data);
	data->current_direction = LEFT;
}

void	d_is_pressed(t_data *data)
{
	if (data->mapp[data->player_x][data->pl_y + 1] == 'T')
	{
		ft_printf("Oh no, Techie caught a bug. GAME OVER\n");
		exit(0);
	}
	if (data->mapp[data->player_x][data->pl_y + 1] == 'E')
	{
		if (win_case(data))
		{
			ft_printf("Cheers! You helped Techie get to the computer and "
				"start working\n P. S. Wish you a bug-free coding experience💻\n");
			exit(0);
		}
		return ;
	}
	if (data->mapp[data->player_x][data->pl_y + 1] != '1')
	{
		data->mapp[data->player_x][data->pl_y + 1] = 'P';
		data->mapp[data->player_x][data->pl_y] = '0';
		data->moves++;
		write_moves(data);
	}
	ternary_to_ord_if(data);
	data->current_direction = RIGHT;
}
