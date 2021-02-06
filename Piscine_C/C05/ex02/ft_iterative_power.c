/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:45:55 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/27 12:43:05 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	result = 1;
	i = power;
	if (power < 0)
		return (0);
	while (i > 0)
	{
		result *= nb;
		i--;
	}
	return (result);
}
