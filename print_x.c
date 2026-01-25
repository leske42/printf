/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:24:16 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/25 17:07:53 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	x_digit_count(unsigned int x)
{
	int	counter;

	counter = 1;
	while (x > 15)
	{
		x = x / 16;
		counter++;
	}
	return (counter);
}

int	print_x(unsigned int x)
{
	if (x > 15)
	{
		print_x(x / 16);
		print_x(x % 16);
	}
	else if (x < 10)
		ft_putchar(x + '0');
	else
		ft_putchar(x - 10 + 'a');
	return (x_digit_count(x));
}

int	print_xup(unsigned int x)
{
	if (x > 15)
	{
		print_xup(x / 16);
		print_xup(x % 16);
	}
	else if (x < 10)
		ft_putchar(x + '0');
	else
		ft_putchar(x - 10 + 'A');
	return (x_digit_count(x));
}
