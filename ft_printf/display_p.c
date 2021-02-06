/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:29:42 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/06 14:50:12 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hexa(t_flags *flags, unsigned long hex)
{
	int size_hex;

	size_hex = 1;
	if (flags->precision == 0 && hex == 0)
		size_hex = 0;
	while (hex / 16 != 0)
	{
		hex /= 16;
		size_hex++;
	}
	return (size_hex);
}

static void	display_ptr(t_flags *flags, unsigned long hex, int size_hex)
{
	char *base;

	base = ft_strdup("0123456789abcdef");
	write(1, "0x", 2);
	flags->printed_characters += 2;
	display_padding_precision(flags, size_hex);
	(flags->precision == 0 && hex == 0) ? 0 : ft_puthexa(flags, hex, base);
	free(base);
}

void		display_p(t_flags *flags, va_list ap)
{
	unsigned long	hex;
	int				real_sz;
	int				size;

	hex = va_arg(ap, unsigned long);
	size = size_hexa(flags, hex);
	real_sz = (flags->precision > size) ? flags->precision : size;
	real_sz += 2;
	if (flags->width != -1)
	{
		if (flags->dash == 1)
		{
			display_ptr(flags, hex, size);
			(real_sz < flags->width) ? display_padding(flags, real_sz, ' ') : 0;
		}
		else
		{
			(real_sz < flags->width) ? display_padding(flags, real_sz, '0') : 0;
			display_ptr(flags, hex, size);
		}
	}
	else
		display_ptr(flags, hex, size);
}
