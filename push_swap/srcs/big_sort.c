/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:19:26 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:54:24 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	convert_to_binary(t_stacks *stacks)
{
	int bit;
	int i;
	int j;
	char *binary;

	binary = (char *)malloc(sizeof(char) * 33);
	if (!binary)
        error_allocation(stacks);
	i = 0;
	while (i < stacks->a.size)
	{
		bit = 31;
		j = 0;
		while (bit >= 0)
		{
			if ((stacks->a.stack[i] >> bit) & 1)
				  binary[j++] = '1';
    		else
				  binary[j++] = '0';
			bit--;
		}
		binary[j] = '\0';
		stacks->a.stack[i++] = ft_atoi(binary);
	}
	if (binary)
		free(binary);
}

void	value_to_pos(t_stacks *stacks)
{
	int i;
	int j;
	int pos;
	int count;
    t_stack *temp;

    temp = copy_stack(stacks->a);
    if (!temp)
       error_allocation(stacks); 
	i = 0;
	while (i < temp->size)
	{
		pos = temp->stack[i];
		count = 0;
		j = 0;
		while (j < temp->size)
		{
			if (i != j && pos > temp->stack[j])
				count++;
			j++;
		}
		stacks->a.stack[i] = count;
		i++;
	}
    if (temp->stack)
		free(temp->stack);
	if (temp)
		free(temp);
}

int size_int(int value)
{
	int size;

	size = 0;
	if (value == 0)
		size++;
	while (value)
	{
		size++;
		value /= 10;
	}
	return (size);
}

int get_nbit(int value, int n)
{
	int n_bit;
	int i;

	i = 1;
	while (i++ < n)
		value /= 10;
	n_bit = value % 10;
	return (n_bit);
}

void	radix_sort(t_stacks *stacks)
{
	int size_origin;
	int max_num;
	int max_bits;
    int i;
	int j;

	value_to_pos(stacks);
	convert_to_binary(stacks);
	size_origin = stacks->a.size;
	max_num = stacks->a.stack[find_max_index(stacks->a)];
	max_bits = size_int(max_num);
	i = 1;
	while (i <= max_bits)
	{
		j = 0;
		while (j < size_origin)
		{
			if (get_nbit(stacks->a.stack[0], i) == 1)
				rotate(stacks->a, 'a');
			else
				push_stack(stacks, 'b');
			j++;
		}
		while (stacks->b.size > 0)
			push_stack(stacks, 'a');
		i++;
	}
}