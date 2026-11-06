/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:16:27 by hlatt             #+#    #+#             */
/*   Updated: 2026/11/02 04:22:42 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);

int		ft_print_char(int c);
int		ft_print_string(const char *c);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int x, int uppercase);
int		ft_print_pointer(void *p);

#endif
