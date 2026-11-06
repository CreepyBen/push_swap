/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:17:09 by ben               #+#    #+#             */
/*   Updated: 2026/11/02 04:17:10 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_nums(int n)
{
	long	temp;
	int		count;

	temp = n;
	if (n < 0)
		temp = -temp;
	if (n == 0)
		count = 1;
	else
	{
		count = 0;
		while (temp > 0)
		{
			temp /= 10;
			count++;
		}
	}
	if (n < 0)
		count++;
	return (count);
}

static char	*itoa(int n)
{
	int			count;
	int			pos;
	long int	temp;
	char		*result;

	count = count_nums(n);
	temp = n;
	result = malloc(count + 1);
	if (!result)
		return (NULL);
	pos = count - 1;
	if (n < 0)
		temp = -temp;
	while (pos >= 0)
	{
		result[pos] = temp % 10 + '0';
		temp /= 10;
		pos--;
	}
	if (n < 0)
		result[0] = '-';
	result[count] = '\0';
	return (result);
}

int	ft_print_number(int n)
{
	char	*str;
	int		i;

	str = itoa(n);
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
