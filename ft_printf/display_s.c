/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 23:11:05 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/06 14:49:53 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*free_substr(t_flags *flags, char *str)
{
	char *sub;

	sub = ft_substr(str, 0, flags->precision);
	free(str);
	return (sub);
}

static char	*null_strdup(char *str)
{
	char *dup;

	dup = ft_strdup("(null)");
	free(str);
	return (dup);
}

void		display_s(t_flags *flags, va_list ap)
{
	char	*str;
	int		size;

	str = ft_strdup(va_arg(ap, char *));
	if (str == NULL)
		str = null_strdup(str);
	if (flags->precision != -1)
		str = free_substr(flags, str);
	size = ft_strlen(str);
	if (flags->width != -1)
	{
		if (flags->dash == 1)
		{
			ft_putstr(flags, str);
			(size < flags->width) ? display_padding(flags, size, ' ') : 0;
		}
		else
		{
			(size < flags->width) ? display_padding(flags, size, '0') : 0;
			ft_putstr(flags, str);
		}
	}
	else
		ft_putstr(flags, str);
	free(str);
}
