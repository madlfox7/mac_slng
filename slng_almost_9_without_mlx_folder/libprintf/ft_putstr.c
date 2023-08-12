/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:33:56 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/02/24 12:05:04 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = NULL;
		write(1, "(null)", 6);
		(*len) += 6;
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i], len);
			i++;
		}
	}
}
