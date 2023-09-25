/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:46:16 by mhuszar           #+#    #+#             */
/*   Updated: 2023/09/25 17:46:18 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	digit_count(int y)
{
	int	counter;
	int	nb;

	counter = 1;
	if (y < 0)
		nb = (y * -1);
	else
		nb = y;
	while (nb > 9)
	{
		nb = nb / 10;
		counter++;
	}
	if (y < 0)
		return (counter + 1);
	else
		return (counter);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int print_i(int i)
{
	ft_putnbr(i);
	return (digit_count(i));
}
