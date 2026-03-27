/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:44:42 by mhuszar           #+#    #+#             */
/*   Updated: 2026/03/27 22:25:27 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill_buf(char *buf, size_t num, int base, int ten)
{
	int	modulo;

	*buf = '\0';
	if (ten == 'P')
		ten = 'a';
	if (!num)
		*(--buf) = '0';
	while (num)
	{
		buf--;
		modulo = num % base;
		num = num / base;
		if (modulo < 10)
			*buf = modulo + '0';
		else
			*buf = modulo - 10 + ten;
	}
	return (buf);
}

int	print_unsigned(size_t num, int mode)
{
	int		base;
	char	buf[23];
	char	*res;

	if (mode == 'P' && !num)
		return (print_s("(nil)"));
	if (!mode)
		base = 10;
	else
		base = 16;
	res = fill_buf(&buf[22], num, base, mode);
	if (mode == 'P')
	{
		*(--res) = 'x';
		*(--res) = '0';
	}
	return (print_s(res));
}
