/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:23:42 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/20 21:23:51 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size_decimal(int n)
{
	int i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static long int		ft_abs(int number)
{
	long int nb;

	nb = number;
	if (number < 0)
		nb = -nb;
	return (nb);
}

char				*ft_itoa(int n)
{
	char		*itoa;
	int			i;
	int			size_decimal;
	long int	nb;
	int			minus;

	minus = (n < 0) ? 1 : 0;
	nb = ft_abs(n);
	size_decimal = ft_size_decimal(n);
	itoa = (char *)malloc(sizeof(*itoa) * size_decimal + 1 + minus);
	if (itoa == NULL)
		return (NULL);
	i = size_decimal + minus;
	itoa[i] = '\0';
	while (--i >= minus)
	{
		itoa[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
