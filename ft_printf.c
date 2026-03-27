/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:58:51 by mhuszar           #+#    #+#             */
/*   Updated: 2026/03/27 22:27:37 by mhuszar          ###   ########.fr       */
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
		len = print_unsigned((size_t)va_arg(*arg_list, void *), 'P');
	else if (typ == 'd')
		len = print_signed(va_arg(*arg_list, int));
	else if (typ == 'i')
		len = print_signed(va_arg(*arg_list, int));
	else if (typ == 'u')
		len = print_unsigned(va_arg(*arg_list, unsigned int), 0);
	else if (typ == 'x')
		len = print_unsigned(va_arg(*arg_list, unsigned int), 'a');
	else if (typ == 'X')
		len = print_unsigned(va_arg(*arg_list, unsigned int), 'A');
	else if (typ == '%')
		len = print_c('%');
	return (len);
}

static bool	flag_check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (true);
	else if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (true);
	else
		return (false);
}

//NOTE: passing NULL as fmt string is undefined (will likely segfault)
int __attribute__ ((format (printf, 1, 2)))
	ft_printf(const char *fmt_str, ...)
{
	int		ctr;
	int		len;
	int		printed;
	va_list	arg_list;

	va_start(arg_list, fmt_str);
	ctr = -1;
	len = 0;
	while (fmt_str[++ctr])
	{
		if (fmt_str[ctr] == '%')
		{
			if (!flag_check(fmt_str[++ctr]))
				return (va_end(arg_list), -1);
			else
				printed = printf_sub(&arg_list, fmt_str[ctr]);
		}
		else
			printed = print_c(fmt_str[ctr]);
		if (printed < 0)
			return (va_end(arg_list), -1);
		len += printed;
	}
	return (va_end(arg_list), len);
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
