/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:59:43 by mhuszar           #+#    #+#             */
/*   Updated: 2026/03/27 22:15:25 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>

int		ft_printf(const char *fmt_str, ...)
		__attribute__ ((format (printf, 1, 2)));
int		print_signed(long int num);
int		print_unsigned(size_t num, int mode);
int		print_c(char c);
int		print_s(char *str);

#endif
