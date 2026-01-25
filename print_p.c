/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:44:42 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/25 17:07:41 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	p_digit_count(unsigned long long int p)
{
	int	counter;

	counter = 1;
	while (p > 15)
	{
		p = p / 16;
		counter++;
	}
	return (counter);
}

static void	print_p_sub(unsigned long long int p)
{
	if (p > 15)
	{
		print_p_sub(p / 16);
		print_p_sub(p % 16);
	}
	else if (p < 10)
		ft_putchar(p + '0');
	else
		ft_putchar(p - 10 + 'a');
}

int	print_p(void *ptr)
{
	unsigned long long int	address;

	address = (unsigned long long int)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	print_p_sub(address);
	return (p_digit_count(address) + 2);
}
