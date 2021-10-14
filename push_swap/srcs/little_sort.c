/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:39:21 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:43:23 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_three(t_stack a)
{
	while (check_sort(a) != 1)
	{
		if (a.size < 3 || (find_max_index(a) == 2 && find_min_index(a) == 1))
			swap_stack(a, 'a');
		else if (find_max_index(a) == 0 && find_min_index(a) == 1)
			rotate(a, 'a');
		else if (find_max_index(a) == 0 && find_min_index(a) == 2)
		{
			swap_stack(a, 'a');
			reverse_rotate(a, 'a');
		}
		else if (find_max_index(a) == 1 && find_min_index(a) == 0)
		{
			swap_stack(a, 'a');
			rotate(a, 'a');
		}
		else if (find_max_index(a) == 1 && find_min_index(a) == 2)
			reverse_rotate(a, 'a');
	}
}

void	sort_stack_five(t_stacks *stacks)
{
	int min;
	
	while (check_sort(stacks->a) != 1)
	{
		while (stacks->a.size != 3)
		{
			min = find_min_index(stacks->a);
			move_index_value(stacks->a, min);
			push_stack(stacks, 'b');
		}
		sort_stack_three(stacks->a);
		while (stacks->b.size != 0)
			push_stack(stacks, 'a');
	}
}
