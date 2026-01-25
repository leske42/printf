/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:58:51 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/25 17:30:34 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_sub(va_list *arg_list, const char typ)
{
	int	len;

	len = 0;
	if (typ == 'c')
		len = print_c(va_arg(*arg_list, int));
	else if (typ == 's')
		len = print_s(va_arg(*arg_list, char *));
	else if (typ == 'p')
		len = print_p(va_arg(*arg_list, void *));
	else if (typ == 'd')
		len = print_i(va_arg(*arg_list, int));
	else if (typ == 'i')
		len = print_i(va_arg(*arg_list, int));
	else if (typ == 'u')
		len = print_u(va_arg(*arg_list, unsigned int));
	else if (typ == 'x')
		len = print_x(va_arg(*arg_list, unsigned int));
	else if (typ == 'X')
		len = print_xup(va_arg(*arg_list, unsigned int));
	else if (typ == '%')
		len = print_c('%');
	return (len);
}

static int	flag_check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	else if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int __attribute__ ((format (printf, 1, 2)))
	ft_printf(const char *fmt_str, ...)
{
	int		counter;
	int		len;
	va_list	arg_list;

	if (!fmt_str)
		return (write(2, "\?\?!!\n", 5));
	va_start(arg_list, fmt_str);
	counter = 0;
	len = 0;
	while (fmt_str[counter])
	{
		if (fmt_str[counter] == '%')
		{
			counter++;
			if (!flag_check(fmt_str[counter]))
				return (va_end(arg_list), -1);
			else
				len = len + printf_sub(&arg_list, fmt_str[counter]);
		}
		else
			len = len + print_c(fmt_str[counter]);
		counter++;
	}
	va_end(arg_list);
	return (len);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *ptr;

	ptr = "salalala";

	ft_printf("alma\n");
	ft_printf("%c\n", 'a');
	ft_printf("%i\n", -4626);

	//ft_printf("%s\n", ptr);
	//ft_printf("%p\n", ptr);
	//printf("%p\n", ptr);

	ft_printf("%s alma %i\n", ptr, -4626);
	
	// printf("%s\n", NULL);
	// ft_printf("%s\n", NULL);
	
	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);

	//printf("%d\n", printf(" %p %p \n", 0, 0));
	//printf("%d\n", ft_printf(" %p %p \n", 0, 0));
	
	// printf("\n%d\n", printf("kalap alma%", "alma"));
	// printf("\n%d\n", ft_printf("kalap alma%", "alma"));
	ft_printf(NULL);
	//printf("kalap alma%\n");
	//ft_printf("kalap alma%\n");
	
	//printf("%X\n", 845639223);
	//ft_printf("%X\n", 845639223);
}*/
