/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:07 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/02/24 12:11:13 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_nbr(unsigned int n, int *len)
{
	if (n == 4294967295)
	{
		write(1, "4294967295", 10);
		*len += 10;
		return ;
	}
	if (n >= 10)
		unsigned_nbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_print_unsigned(unsigned int n, char type, int *len)
{
	if (type == 'u')
		unsigned_nbr(n, len);
	else if (type == 'x')
		print_hex(n, 0, len);
	else if (type == 'X')
		print_hex(n, 1, len);
}
