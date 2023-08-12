#include "so_long.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && ft_strchr_v(set, s1[start]))
		start++;
	end = ft_strlen_v(s1);
	while (end && ft_strchr_v(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

void	split_clean(char **split_res)
{
	int	i;

	i = 0;
	while (split_res[i])
	{
		free(split_res[i]);
		i++;
	}
	free(split_res);
}

void	nl_in_between(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("Error\nEmpty line\n");
			exit(1);
		}
		i++;
	}
}

void	get_width(char **res, int *width)
{
	int	i;
	int	etalon;
	int	current_width;

	etalon = ft_strlen(res[0]);
	i = 0;
	while (res[i] != NULL)
	{
		current_width = ft_strlen(res[i]);
		if (res[i][current_width] != '\0' && res[i][current_width] != '\n')
		{
			ft_printf("Error: Line %d is not properly terminated", i);
			exit(1);
		}
		if (current_width != etalon)
		{
			ft_printf("Error\nLine %d. Etalon width: %d, Current width: %d\n",
				i, etalon, current_width);
			exit(1);
		}
		i++;
	}
	*width = etalon;
}

void	trim(t_data *data, char *str, int *height, int *width)
{
	char	**res;
	int		size;

	size = 0;
	res = call_split(str, &size);
	check_lines_len(res);
	*height = size;
	get_width(res, width);
	allocate_map(data);
	init_vals(res, data);
	split_clean(res);
}
