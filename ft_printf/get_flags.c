/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:32:36 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/04 17:32:37 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->dash = -1;
	flags->zero = -1;
	flags->width = -1;
	flags->precision = -1;
}

int		get_number(const char *format, t_flags *flags, int i)
{
	int count;

	count = i;
	flags->width = 0;
	while (ft_isdigit(format[count]))
	{
		flags->width *= 10;
		flags->width += format[count] - '0';
		count++;
	}
	return (count);
}

int		get_precision(const char *f, t_flags *flags, va_list ap, int i)
{
	int count;

	count = i;
	flags->precision = 0;
	flags->zero = -1;
	if (f[count] == '*')
	{
		flags->precision = va_arg(ap, int);
		count++;
	}
	else if (ft_isdigit(f[count]))
	{
		while (ft_isdigit(f[count]))
		{
			flags->precision *= 10;
			flags->precision += f[count] - '0';
			count++;
		}
	}
	if (flags->precision < 0)
		flags->precision = -1;
	return (count);
}

int		get_dash_zero(const char *format, t_flags *flags, int i)
{
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			flags->dash = 1;
			flags->zero = -1;
		}
		else if (format[i] == '0' && flags->dash == -1)
			flags->zero = 1;
		i++;
	}
	return (i);
}

void	get_flags(const char *f, t_flags *flags, va_list ap, int i)
{
	i = get_dash_zero(f, flags, i);
	if (f[i] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->width = -flags->width;
			flags->dash = 1;
			flags->zero = -1;
		}
		i++;
	}
	if (ft_isdigit(f[i]))
		i = get_number(f, flags, i);
	if (f[i++] == '.')
		i = get_precision(f, flags, ap, i);
}
