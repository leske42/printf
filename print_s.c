/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:05:23 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/25 17:35:34 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	int	ctr;

	ctr = 0;
	while (s[ctr] != 0)
		ctr++;
	return (ctr);
}

int	print_s(char *str)
{
	int	counter;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	counter = ft_strlen(str);
	write(1, str, counter);
	return (counter);
}
