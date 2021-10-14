/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:52:00 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:38:53 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insertion_sort(t_stacks *stacks)
{
	int min;

	while (check_sort(stacks->a) != 1)
	{
		while (stacks->a.size > 0)
		{
			min = find_min_index(stacks->a);
			move_index_value(stacks->a, min);
			push_stack(stacks, 'b');
		}
		while(stacks->b.size > 0)
			push_stack(stacks, 'a');
	}
}
