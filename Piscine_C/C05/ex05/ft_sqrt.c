/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:52:26 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/27 15:16:37 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb >= 0)
	{
		if (nb == 1)
			return (1);
		while (i <= nb && i <= 46340)
		{
			if (i * i == nb)
				return (i);
			i++;
		}
		return (0);
	}
	return (0);
}
