/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:52:26 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/12 19:39:03 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_arg(char **arg)
{
	int i;
	int j;
	int digit;

	i = 0;
	while (arg[++i])
	{
		j = 0;
		digit = 0;
		while (arg[i][j] != '\0')
		{
			while (arg[i][j] == '+' || arg[i][j] == '-')
				j++;
			if (arg[i][j] != '\0')
				digit = ft_isdigit(arg[i][j]);
			if (digit != 1)
			{
				ft_putstr_fd("Error: one argument is not integer!\n", 1);
				return (ERROR);
			}
			j++;
		}
	}
	return (SUCCESS);
}

int	check_duplicates(t_stacks *stacks)
{
	int i;
	int j;
	int error;

	i = 0;
	error = 0;
	while (i < stacks->a.size)
	{
		j = 0;
		while (j < stacks->a.size)
		{
			if (i != j && stacks->a.stack[i] == stacks->a.stack[j])
				error = -1;
			j++;
		}
		i++;
	}
	if (error == -1)
		ft_putstr_fd("Error: duplicates!\n", 1);
	return (error);
}

int	check_sort(t_stack a)
{
	int i;
	int sort;

	i = 0;
	sort = 1;
	while (i < a.size - 1)
	{
		if (a.stack[i] >= a.stack[i + 1])
			sort = -1;
		i++;
	}
	return (sort);
}