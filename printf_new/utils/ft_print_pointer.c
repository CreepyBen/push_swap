/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:17:06 by ben               #+#    #+#             */
/*   Updated: 2026/11/02 04:18:42 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_digits(char *hex, int i)
{
	int	count;

	count = 0;
	while (i < 16)
	{
		write(1, &hex[i], 1);
		i++;
		count++;
	}
	return (count);
}

static int	print_pointer_hex(unsigned long addr)
{
	char	*hex_digits;
	char	hex[16];
	int		i;

	i = 16;
	hex_digits = "0123456789abcdef";
	while (addr > 0)
	{
		i--;
		hex[i] = hex_digits[addr % 16];
		addr /= 16;
	}
	return (print_digits(hex, i));
}

int	ft_print_pointer(void *p)
{
	int	result;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	result = print_pointer_hex((unsigned long)p);
	return (result + 2);
}
