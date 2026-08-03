/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:56:16 by rafreire          #+#    #+#             */
/*   Updated: 2025/08/05 19:04:47 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *total_prints);
void	ft_putstr(char *str, int *total_prints);
void	set_char(va_list *args, int *total_prints, int *count);
void	set_string(va_list *args, int *total_prints, int *count);
void	set_putnb_printf(va_list *args, int *total_prints, int *count);
void	rec_print_digits(int nb, int *total_prints);
void	rec_convertnb(unsigned int nb, char *base,
			int base_len, int *total_prints);
void	ft_convert_nb(va_list *args, char base,
			int *total_prints, int *count);
void	rec_convertnb(unsigned int nb, char *base,
			int u_len, int *total_prints);
void	ft_convert_ptr(va_list *args, char base,
			int *total_prints, int *count);
void	rec_convertptr(unsigned long nb, char *base,
			int base_len, int *total_prints);
void	ft_specifier(const char *format, va_list *args,
			int *total_prints, int *count);

#endif