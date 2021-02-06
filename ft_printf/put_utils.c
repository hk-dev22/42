/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:44:26 by hkortbi           #+#    #+#             */
/*   Updated: 2021/02/06 13:16:19 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(t_flags *flags, int n)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		flags->printed_characters++;
		nbr = -nbr;
	}
	if (nbr <= 9)
	{
		ft_putchar(nbr + '0');
		flags->printed_characters++;
	}
	else
	{
		ft_putnbr(flags, nbr / 10);
		ft_putchar(nbr % 10 + '0');
		flags->printed_characters++;
	}
}

void	ft_putnbr_u(t_flags *flags, unsigned int n)
{
	if (n <= 9)
	{
		ft_putchar(n + '0');
		flags->printed_characters++;
	}
	else
	{
		ft_putnbr(flags, n / 10);
		ft_putchar(n % 10 + '0');
		flags->printed_characters++;
	}
}

void	ft_putstr(t_flags *flags, char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		flags->printed_characters++;
		i++;
	}
}

void	ft_puthexa(t_flags *flags, unsigned long nb, char *base)
{
	unsigned long	div;
	unsigned long	mod;

	div = nb / 16;
	mod = nb % 16;
	if (div != 0)
	{
		ft_puthexa(flags, div, base);
	}
	ft_putchar(base[mod]);
	flags->printed_characters++;
}

void	ft_putchar_print(t_flags *flags, char c)
{
	ft_putchar(c);
	flags->printed_characters++;
}
