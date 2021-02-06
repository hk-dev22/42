/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:56:09 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/04 20:56:11 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_c(t_flags *flags, char c)
{
	if (flags->width != -1)
	{
		if (flags->dash == 1)
		{
			ft_putchar(c);
			flags->printed_characters++;
			display_padding(flags, 1, ' ');
		}
		else
		{
			display_padding(flags, 1, '0');
			ft_putchar_print(flags, c);
		}
	}
	else
		ft_putchar_print(flags, c);
}
