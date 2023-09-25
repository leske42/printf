/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:58:51 by mhuszar           #+#    #+#             */
/*   Updated: 2023/09/25 15:58:54 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *tipus, ...)
{
	va_list arg_list; //I create a variable for the list of arguments.
	va_start(arg_list, tipus); //I specify format as the first element of this list
	int	counter;

	counter = 0;
	while (format[counter])
	{
		if format[counter] = '%'
		{
			counter++;
			if (tipus[counter] = 'c')
				return (print_c(va_arg(arg_list, char)));
			else if (tipus[counter] = 's')
				return (print_s(va_arg(arg_list, *char)));
			else if (tipus[counter] = 'p')
				//p;
			else if (tipus[counter] = 'd')
				//d;
			else if (tipus[counter] = 'i')
				return (print_i(va_arg(arg_list, int)));
			else if (tipus[counter] = 'u')
				//u;
			else if (tipus[counter] = 'x')
				print_x(va_arg(arg_list, unsigned int)));
			else if (tipus[counter] = 'X')
				print_xup(va_arg(arg_list, unsigned int)));
			else if (tipus[counter] = '%')
				return (print_c('%'));
			else
				return ((print_s(tipus));
		}
	}
	return (0);
}

int	main(void)
{
	ft_printf("alma");
	ft_printf("%s", "alma");
	ft_printf("%c", 'a');
	ft_printf("%i", -4626);
}
			
