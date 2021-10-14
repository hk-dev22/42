/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:07:12 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/09 14:10:50 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sa or sb
void    swap_stack(t_stack s, char ab)
{
    int temp;

    if (s.size > 1)
    {
        temp = s.stack[0];
        s.stack[0] = s.stack[1];
        s.stack[1] = temp;
    }
	if (ab == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

//ss
void	swap_ss(t_stacks *stacks)
{
	swap_stack(stacks->a, 'a');
	swap_stack(stacks->b, 'b');
}
