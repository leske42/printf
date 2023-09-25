/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:33:17 by mhuszar           #+#    #+#             */
/*   Updated: 2023/09/25 19:33:19 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	digit_u(int y)
{
	int	counter;

	counter = 1;
	while (y > 9)
	{
		y = y / 10;
		counter++;
	}
	return (counter);
}

static void	put_u(unsigned int u)
{
	if (u > 9)
	{
		put_u(u / 10);
		put_u(u % 10);
	}
	else
		ft_putchar(u + '0');
}

int	print_u(unsigned int u)
{
	put_u(u);
	return (digit_u(u));
}
