/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:19:52 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:42:29 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_stacks *stacks, char ab)
{
	if (ab == 'a')
	{
		if (stacks->b.size != 0)
		{
			stacks->a.stack = ft_realloc_stack(stacks->a, 1, 1, 0);
			stacks->a.size += 1;
			stacks->a.stack[0] = stacks->b.stack[0];
			stacks->b.stack = ft_realloc_stack(stacks->b, -1, 0, 1);
			stacks->b.size -=1;
		}
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		if (stacks->a.size != 0)
		{
			stacks->b.stack = ft_realloc_stack(stacks->b, 1, 1, 0);
			stacks->b.size += 1;
			stacks->b.stack[0] = stacks->a.stack[0];
			stacks->a.stack = ft_realloc_stack(stacks->a, -1, 0, 1);
			stacks->a.size -=1;
		}
		ft_putstr_fd("pb\n", 1);
	}
}