/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:41:38 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/08/12 17:41:39 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 10000

char	*get_next_line(int fd)
{
	char	*buffer;
	int		i;
	int		rd;
	char	character;

	i = 0;
	rd = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(100000);
	if (!buffer)
		return (NULL);
	while (read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1) > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
