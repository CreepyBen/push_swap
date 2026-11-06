/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:56:39 by ben               #+#    #+#             */
/*   Updated: 2026/11/02 04:17:13 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	hex_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static char	*xtoa(unsigned int n, int uppercase)
{
	char	*hex;
	char	*str;
	int		count;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = hex_digits(n);
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		str[count] = hex[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_print_hex(unsigned int x, int uppercase)
{
	char	*str;
	int		i;

	str = xtoa(x, uppercase);
	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
