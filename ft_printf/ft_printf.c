/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:21:54 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/06 13:14:13 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char flag)
{
	if (flag == '-' || flag == '0' || flag == '*' || flag == '.')
		return (1);
	else
		return (0);
}

static int	ft_isflag(char c)
{
	if (ft_isdigit(c) || check_flag(c))
		return (1);
	else
		return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_flags flags;
	int		i;

	va_start(ap, format);
	i = 0;
	flags.printed_characters = 0;
	while (format[i] != '\0')
	{
		init_flags(&flags);
		if (format[i] == '%')
		{
			i++;
			if (ft_isflag(format[i]))
				get_flags(format, &flags, ap, i);
			while (ft_isflag(format[i]) && format[i + 1] != '\0')
				i++;
			display_manager(&flags, ap, format[i]);
		}
		else
			ft_putchar_print(&flags, format[i]);
		i++;
	}
	va_end(ap);
	return (flags.printed_characters);
}
