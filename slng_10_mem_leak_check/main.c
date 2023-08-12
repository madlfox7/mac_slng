/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <ksudzilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:40:06 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/08/12 19:28:11 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	write_moves(t_data *data)
{
	char	*move_str;
	int		text_color;

	move_str = ft_itoa(data->moves);
	text_color = 0xF5F5DC;
	mlx_string_put(data->mlx, data->win, 20, 24, text_color, move_str);
	free(move_str);
	return (0);
}

void	get_map2(int fd, char *res, char *str, t_data *data)
{
	close(fd);
	res = ft_strtrim(str, "\n");
	nl_in_between(res);
	trim(data, res, &(data->height), &(data->width));
	free(str);
	free(res);
}

void	get_map1(char *filename, t_data *data)
{
	char	*str;
	int		fd;
	char	*line;
	char	*res;

	str = NULL;
	res = NULL;
	line = NULL;
	fd = open(filename, O_RDONLY);
	file_error_msg(fd, line, 1);
	line = get_next_line(fd);
	file_error_msg(fd, line, 2);
	str = ft_calloc(1, 1);
	while (line)
	{
		str = ft_strjoin2(str, line);
		free(line);
		line = get_next_line(fd);
	}
	get_map2(fd, res, str, data);
}

void	map_validation(t_data *data)
{
	if (!valid(data))
	{
		ft_printf("Error: invalid character in the line\n");
		system("leaks so_long");
		exit(1);
	}
	if (data->height > 16 || data->width > 32)
	{
		ft_printf("The map is too big for this screen\n");
		system("leaks so_long");
		exit(0);
	}
	borders(data);
	if (!is_map_valid(data))
	{
	system("leaks so_long");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Memory allocation error\n");
		exit(1);
	}
	data->width = 0;
	data->height = 0;
	data->mp = NULL;
	if (argc == 2)
	{
		check_filename(argv[1]);
		get_map1(argv[1], data);
	}
	else
	{
		ft_printf("Usage: %s <filename>(or path)\n", argv[0]);
		return (1);
	}
	map_validation(data);
	graphics(data);
	free_data(data);
	system("leaks so_long");
	return (0);
}
