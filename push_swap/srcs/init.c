/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:02:10 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/09 14:10:30 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks *init_stacks(int sizeOrigin)
{
    t_stacks *stacks;

    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    stacks->a.stack = (int *)malloc(sizeof(int) * sizeOrigin);
    stacks->b.stack = NULL;
    stacks->a.size = sizeOrigin;
    stacks->b.size = 0;
    return (stacks);
}

void	init_stackA(t_stacks *stacks, char **av)
{
	int i;
	
	i = 1;
	while (i <= stacks->a.size)
	{
		stacks->a.stack[i - 1] = ft_atoi_modified(av[i], stacks);
		i++;
	}
}