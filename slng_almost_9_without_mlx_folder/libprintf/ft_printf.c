/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksudzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:01:54 by ksudzilo          #+#    #+#             */
/*   Updated: 2023/02/24 12:01:56 by ksudzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	select_specifier(char s, va_list *args, int *len)
{
	if (s == '%')
		ft_putchar('%', len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'u' || s == 'x' || s == 'X')
		ft_print_unsigned(va_arg(*args, unsigned int), s, len);
	else if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'p')
	{
		ft_putstr("0x", len);
		print_hex((unsigned long long)va_arg(*args, void *), 0, len);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(params, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			select_specifier(format[i], &params, &len);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(params);
	return (len);
}
