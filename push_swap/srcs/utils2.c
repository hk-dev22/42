/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:39:52 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:40:57 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_index(t_stack a)
{
	int i;
	int min_index;
	int min;

	min = a.stack[0];
	min_index = 0;
	i = 1;
	while (i < a.size)
	{
		if (min > a.stack[i])
		{
			min = a.stack[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_max_index(t_stack a)
{
	int i;
	int max_index;
	int max;

	max = a.stack[0];
	max_index = 0;
	i = 1;
	while (i < a.size)
	{
		if (max < a.stack[i])
		{
			max = a.stack[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}


void	move_index_value(t_stack a, int index)
{
	if (a.size != 0)
	{
		if (index <= a.size / 2)
		{
			while (index-- > 0)
				rotate(a, 'a');
		}
		else
		{
			while (index++ < a.size)
				reverse_rotate(a, 'a');
		}
	}
}