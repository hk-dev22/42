/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 01:23:40 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/05 01:23:41 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hexa(t_flags *flags, unsigned int hex)
{
	int size_hex;

	if (flags->precision == 0 && hex == 0)
		size_hex = 0;
	else
		size_hex = 1;
	while (hex / 16 != 0)
	{
		hex /= 16;
		size_hex++;
	}
	return (size_hex);
}

static void	display_hexa(t_flags *flags, unsigned int hex, char t, int size_hex)
{
	char *base;

	base = ft_strdup("0123456789abcdef");
	if (t == 'X')
		base = ft_strupcase(base);
	display_padding_precision(flags, size_hex);
	(flags->precision == 0 && hex == 0) ? 0 : ft_puthexa(flags, hex, base);
	free(base);
}

void		display_h(t_flags *flags, va_list ap, char type)
{
	unsigned int	hex;
	int				real_sz;
	int				size;

	hex = va_arg(ap, unsigned int);
	size = size_hexa(flags, hex);
	real_sz = (flags->precision > size) ? flags->precision : size;
	if (flags->width != -1)
	{
		if (flags->dash == 1)
		{
			display_hexa(flags, hex, type, size);
			(real_sz < flags->width) ? display_padding(flags, real_sz, ' ') : 0;
		}
		else
		{
			(real_sz < flags->width) ? display_padding(flags, real_sz, '0') : 0;
			display_hexa(flags, hex, type, size);
		}
	}
	else
		display_hexa(flags, hex, type, size);
}
