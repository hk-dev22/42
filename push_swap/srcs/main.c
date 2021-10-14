/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:34:19 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:36:04 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
	t_stacks *stacks;
	int error;

    if (ac <= 1)
	{
        ft_putstr_fd("Error: wrong number of arguments!\n", 1);
		return (-1);
	}
	if (check_arg(av) != ERROR)
	{
		stacks = init_stacks(ac - 1);
		init_stackA(stacks, av);
		error = check_duplicates(stacks);
		if (error == -1)
			exit_all(stacks);
		if (check_sort(stacks->a) == -1)
		{
			if (stacks->a.size <= 3)
				sort_stack_three(stacks->a);
			else if (stacks->a.size <= 5)
				sort_stack_five(stacks);
			else
				radix_sort(stacks);
		}
		exit_all(stacks);
	}
}