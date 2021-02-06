/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:44:41 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/05 12:44:43 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	handle_uint(int n)
{
	long	max_uint;

	max_uint = 4294967296;
	if (n < 0)
		return (max_uint + n);
	return (n);
}

static int			size_num(t_flags *flags, unsigned int n)
{
	int	i;

	if (n == 0 && flags->precision == 0)
		i = 0;
	else
		i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void			display_number(t_flags *flags, unsigned int n, int size_num)
{
	display_padding_precision(flags, size_num);
	(n == 0 && flags->precision == 0) ? 0 : ft_putnbr_u(flags, n);
}

void				display_u(t_flags *flags, va_list ap)
{
	unsigned int	n;
	int				size_n;
	int				real_sn;

	n = handle_uint(va_arg(ap, int));
	size_n = size_num(flags, n);
	real_sn = (flags->precision > size_n) ? flags->precision : size_n;
	if (flags->width != -1)
	{
		if (flags->dash == 1)
		{
			display_number(flags, n, size_n);
			(real_sn < flags->width) ? display_padding(flags, real_sn, ' ') : 0;
		}
		else
		{
			(real_sn < flags->width) ? display_padding(flags, real_sn, '0') : 0;
			display_number(flags, n, size_n);
		}
	}
	else
		display_number(flags, n, size_n);
}
