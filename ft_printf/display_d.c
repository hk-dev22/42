/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:09:56 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/04 21:09:58 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_num(t_flags *flags, int n)
{
	int i;
	int nbr;

	if (n == 0 && flags->precision == 0)
		nbr = 0;
	else
		nbr = 1;
	i = n;
	while (i / 10 != 0)
	{
		i = i / 10;
		nbr++;
	}
	return (nbr);
}

static int	real_size(t_flags *flags, int n, int size_num)
{
	int real_size;

	real_size = size_num;
	if (flags->precision > size_num)
		real_size = flags->precision;
	if (n < 0)
		real_size++;
	return (real_size);
}

static void	display_number(t_flags *flags, int n, int size_num)
{
	if (n < 0 && flags->precision > size_num)
	{
		n = -n;
		write(1, "-", 1);
		flags->printed_characters++;
	}
	display_padding_precision(flags, size_num);
	(n == 0 && flags->precision == 0) ? 0 : ft_putnbr(flags, n);
}

static int	display_dash(t_flags *flags, int n)
{
	n = -n;
	write(1, "-", 1);
	flags->printed_characters++;
	return (n);
}

void		display_d(t_flags *flags, va_list ap)
{
	int n;
	int size_n;
	int real_sn;

	n = va_arg(ap, int);
	size_n = size_num(flags, n);
	real_sn = real_size(flags, n, size_n);
	if (flags->width != -1)
	{
		if (flags->dash == 1)
		{
			display_number(flags, n, size_n);
			(real_sn < flags->width) ? display_padding(flags, real_sn, ' ') : 0;
		}
		else
		{
			if (n < 0 && flags->zero == 1)
				n = display_dash(flags, n);
			(real_sn < flags->width) ? display_padding(flags, real_sn, '0') : 0;
			display_number(flags, n, size_n);
		}
	}
	else
		display_number(flags, n, size_n);
}
