/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:35:46 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/06 13:48:12 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_manager(t_flags *flags, va_list ap, char type)
{
	if (type == 'c')
		display_c(flags, va_arg(ap, int));
	else if (type == '%')
		display_c(flags, '%');
	else if (type == 'd' || type == 'i')
		display_d(flags, ap);
	else if (type == 'u')
		display_u(flags, ap);
	else if (type == 's')
		display_s(flags, ap);
	else if (type == 'x' || type == 'X')
		display_h(flags, ap, type);
	else if (type == 'p')
		display_p(flags, ap);
	else
		ft_putchar_print(flags, type);
}

void	display_padding(t_flags *flags, int n, char c)
{
	int	i;
	int	npadd;

	i = 0;
	npadd = flags->width - n;
	if (flags->zero != 1)
		c = ' ';
	while (i++ < npadd)
		ft_putchar_print(flags, c);
}

void	display_padding_precision(t_flags *flags, int n)
{
	int	i;
	int	npadd;

	i = 0;
	npadd = flags->precision - n;
	while (i++ < npadd)
		ft_putchar_print(flags, '0');
}
