/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:14:23 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/14 21:42:22 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "limits.h"

#define SUCCESS 1
#define ERROR -1

typedef struct s_stack
{
	int *stack;
	int size;
}			t_stack;

typedef struct s_stacks
{
	t_stack a;
	t_stack b;
}				t_stacks;

t_stacks *init_stacks(int sizeOrigin);
void	init_stackA(t_stacks *stacks, char **av);
void    exit_all(t_stacks *stacks);
void    swap_stack(t_stack stack, char ab);
int		check_arg(char **arg);
int		check_duplicates(t_stacks *stacks);
void	swap_ss(t_stacks *stacks);
int		*ft_memcpy_m(int *dest, const int *src, int n, int start, int start2);
int *ft_realloc_stack(t_stack s, int n, int start, int start2);
void	print_stack(t_stacks *stacks);
int		ft_atoi_modified(const char *str, t_stacks *stacks);
void	push_stack(t_stacks *stacks, char ab);
void    rotate(t_stack s, char ab);
void	rotate_rr(t_stacks *stacks);
void	reverse_rotate(t_stack s, char ab);
void	reverse_rotate_rr(t_stacks *stacks);
int		check_sort(t_stack a);
void	sort_stack_three(t_stack a);
void	sort_stack_five(t_stacks *stacks);
int		max_stack(t_stack s);
t_stack	*copy_stack(t_stack a);
int		min_stack(t_stack s);
void	sort_stack_five(t_stacks *stacks);
int		find_min_index(t_stack a);
int		find_max_index(t_stack a);
void	radix_sort(t_stacks *stacks);
void	move_index_value(t_stack a, int index);
void	insertion_sort(t_stacks *stacks);
void    error_allocation(t_stacks *stacks);

#endif