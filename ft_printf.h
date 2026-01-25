/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:59:43 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/25 17:30:39 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *tipus, ...)
		__attribute__ ((format (printf, 1, 2)));
void	ft_putchar(char c);
int		print_i(int i);
int		print_x(unsigned int x);
int		print_xup(unsigned int x);
int		print_c(char c);
int		print_s(char *str);
int		print_p(void *ptr);
int		print_u(unsigned int u);

#endif
