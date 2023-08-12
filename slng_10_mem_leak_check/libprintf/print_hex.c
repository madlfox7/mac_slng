/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:08:01 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/02/24 12:16:59 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long long n, int caps, int *len)
{
	char	hex[16];
	int		i;
	int		rem;

	i = 0;
	while (n > 0)
	{
		rem = n % 16;
		if (rem < 10)
			hex[i++] = rem + '0';
		else if (caps)
			hex[i++] = rem - 10 + 'A';
		else
			hex[i++] = rem - 10 + 'a';
		n /= 16;
	}
	if (i == 0)
		ft_putchar('0', len);
	else
	{
		while (i--)
		{
			ft_putchar(hex[i], len);
		}
	}
}
