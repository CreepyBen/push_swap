/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:17:00 by ben               #+#    #+#             */
/*   Updated: 2026/11/02 04:17:02 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_digits(char *arr, int i)
{
	int	count;

	count = 0;
	while (i < 10)
	{
		write(1, &arr[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	char	arr[10];
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 10;
	while (n > 0)
	{
		i--;
		arr[i] = n % 10 + '0';
		n /= 10;
	}
	return (print_digits(arr, i));
}
