/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:52:19 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:40:54 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stacks *stacks)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < stacks->a.size || j < stacks->b.size)
	{
		if (i < stacks->a.size)
			ft_putstr_fd(ft_itoa(stacks->a.stack[i]), 1);
		ft_putchar_fd('|', 1);
		if (j < stacks->b.size)
			ft_putstr_fd(ft_itoa(stacks->b.stack[i]), 1);
		ft_putchar_fd('\n', 1);
		i++;
		j++;
	}
	ft_putstr_fd("a|b\n", 1);
}


int	ft_atoi_modified(const char *str, t_stacks *stacks)
{
	int i;
	int minus;
	long atoi;

	i = 0;
	minus = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		atoi *= 10;
		atoi += str[i] - '0';
		i++;
	}
	if (atoi > INT_MAX || atoi < INT_MIN)
	{
		ft_putstr_fd("Error: one argument not in range of int!\n", 1);
		exit_all(stacks);
	}
	return (atoi * minus);
}

int	*ft_memcpy_m(int *dest, const int *src, int n, int start, int start2)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	// printf("%d, %d, %d, %d\n", i, n, start, start2);
	while (i + start < n)
	{
		dest[i + start] = src[i + start2];
		i++;
	}
	return (dest);
}

int *ft_realloc_stack(t_stack s, int n, int start, int start2)
{
	int *temp;
	
	// printf("%d, %d\n", s.size, n);
	temp = (int *)malloc(sizeof(int) * (s.size + n));
	if (!temp)
		return (NULL);
	if (temp && s.stack)
		ft_memcpy_m(temp, s.stack, s.size + n, start, start2);
	if (s.stack)
		free(s.stack);
	return temp;
}

t_stack	*copy_stack(t_stack a)
{
	t_stack *temp;
	int i;

	temp = (t_stack *)malloc(sizeof(t_stack));
	temp->stack = (int *)malloc(sizeof(int) * a.size);
	if (!temp->stack || !temp)
		return (NULL);
	i = 0;
	while (i < a.size)
	{
		temp->stack[i] = a.stack[i];
		i++;
	}
	temp->size = a.size;
	return (temp);
}

