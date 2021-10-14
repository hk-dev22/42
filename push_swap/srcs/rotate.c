/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:32:41 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/09 14:10:37 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate(t_stack s, char ab)
{
    int i;
    int temp;

    i = 0;
    temp = s.stack[0];
    while (i < s.size - 1)
    {
        s.stack[i] = s.stack[i + 1];
        i++;
    }
    s.stack[s.size - 1] = temp;
	if (ab == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	rotate_rr(t_stacks *stacks)
{
	rotate(stacks->a, 'a');
	rotate(stacks->b, 'b');
}

void	reverse_rotate(t_stack s, char ab)
{
	int i;
    int temp;

    i = s.size - 1;
    temp = s.stack[s.size - 1];
    while (i > 0)
    {
        s.stack[i] = s.stack[i - 1];
        i--;
    }
    s.stack[0] = temp;
	if (ab == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrbb\n", 1);
}

void	reverse_rotate_rr(t_stacks *stacks)
{
	reverse_rotate(stacks->a, 'a');
	reverse_rotate(stacks->b, 'b');
}