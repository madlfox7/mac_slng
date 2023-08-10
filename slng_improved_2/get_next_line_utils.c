#include "so_long.h"

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	while (s != 0 && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
