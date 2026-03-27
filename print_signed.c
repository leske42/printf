/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:46:16 by mhuszar           #+#    #+#             */
/*   Updated: 2026/03/27 22:25:18 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_signed(long int num)
{
	char		buf[12];
	int			idx;
	bool		negative;

	if (!num)
		return (print_c('0'));
	negative = (num < 0);
	if (negative)
		num *= -1;
	idx = 11;
	buf[idx] = '\0';
	while (num)
	{
		idx--;
		buf[idx] = num % 10 + '0';
		num = num / 10;
	}
	if (negative)
		buf[--idx] = '-';
	return (print_s(&buf[idx]));
}
