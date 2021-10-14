/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:23:21 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:29:33 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    exit_all(t_stacks *stacks)
{
    if (stacks->a.stack)
        free(stacks->a.stack);
    if (stacks->b.stack)
        free(stacks->b.stack);
    if (stacks)
        free(stacks);
    exit(0);
}

void    error_allocation(t_stacks *stacks)
{
    ft_putstr_fd("Error: memory allocation!\n", 1);
    exit_all(stacks);
}