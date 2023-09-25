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
//#include <stdarg.h>

static int	printf_sub(va_list arg_list, char typ)
{
	int	len;

	len = 0;
	if (typ == 'c')
		len = print_c(va_arg(arg_list, int));
	else if (typ == 's')
		len = print_s(va_arg(arg_list, char *));
	else if (typ == 'p')
		len = print_p(va_arg(arg_list, void *));
	else if (typ == 'd')
		len = print_i(va_arg(arg_list, int));
	else if (typ == 'i')
		len = print_i(va_arg(arg_list, int));
	else if (typ == 'u')
		len = print_u(va_arg(arg_list, unsigned int));
	else if (typ == 'x')
		len = print_x(va_arg(arg_list, unsigned int));
	else if (typ == 'X')
		len = print_xup(va_arg(arg_list, unsigned int));
	else if (typ == '%')
		len = print_c('%');
	return (len);
}

int	ft_printf(const char *tipus, ...)
{
	va_list arg_list; //I create a variable for the list of arguments.
	va_start(arg_list, tipus); //I specify format as the first element of this list
	int	counter;
	int	len;

	counter = 0;
	len = 0;
	while (tipus[counter])
	{
		if (tipus[counter] == '%')
		{
			counter++;
			len = len + printf_sub(arg_list, tipus[counter]);
		}
		else
			len = len + print_c(tipus[counter]);
		counter++;
	}
	va_end(arg_list);
	return (len);
}

int	main(void)
{
	ft_printf("alma\n");
	ft_printf("%s\n", "alma");
	ft_printf("%c\n", 'a');
	ft_printf("%i\n", -4626);
}
