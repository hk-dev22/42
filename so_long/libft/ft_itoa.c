/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:23:42 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/08 00:43:51 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_decimal(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static long int	ft_abs(int number)
{
	long int	nb;

	nb = number;
	if (number < 0)
		nb = -nb;
	return (nb);
}

int	ft_negative(int nbr)
{
	if (nbr < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	int			i;
	int			size_decimal;
	long int	nb;
	int			minus;

	minus = ft_negative(n);
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
