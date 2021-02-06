/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:22:15 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/06 13:13:27 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <stdint.h>

typedef struct	s_flags
{
	int dash;
	int zero;
	int width;
	int precision;
	int printed_characters;
}				t_flags;

int				ft_printf(const char *format, ...);
void			init_flags(t_flags *flags);
void			get_flags(const char *f, t_flags *flags, va_list ap, int i);
int				get_number(const char *format, t_flags *flags, int i);
int				get_precision(const char *f, t_flags *flags, va_list ap, int i);
int				get_dash_zero(const char *format, t_flags *flags, int i);
void			display_manager(t_flags *flags, va_list ap, char type);
void			display_c(t_flags *flags, char c);
void			display_d(t_flags *flags, va_list ap);
void			display_u(t_flags *flags, va_list ap);
void			display_s(t_flags *flags, va_list ap);
void			display_h(t_flags *flags, va_list ap, char type);
void			display_p(t_flags *flags, va_list ap);
void			display_pct(t_flags *flags, char c);
void			display_padding(t_flags *flags, int n, char c);
void			display_padding_precision(t_flags *flags, int n);
void			ft_putnbr(t_flags *flags, int n);
void			ft_putstr(t_flags *flags, char *s);
void			ft_putnbr_u(t_flags *flags, unsigned int n);
void			ft_puthexa(t_flags *flags, unsigned long nb, char *base);
void			ft_putchar_print(t_flags *flags, char c);

#endif
