/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:16:55 by ben               #+#    #+#             */
/*   Updated: 2026/11/02 05:14:35 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char c, va_list arg)
{
	if (c == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_number(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), c == 'X'));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(arg, void *)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	if (!s)
		return (-1);
	va_start(arg, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			count += handle_conversion(s[i], arg);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
