/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:49:25 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/27 16:36:08 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_array(int *aray, int n);
void	ft_initialize_array(int *array, int n);
void	ft_array_combn(int *array, int n, int k);
void	ft_print_combn(int n);

void		ft_print_combn(int n)
{
	int array[n];
	int i;

	if (n < 1 || n > 11)
		return ;
	i = n;
	ft_initialize_array(array, n);
	ft_array_combn(array, n, i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print_array(int *array, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(array[i] + '0');
		i++;
	}
	if (array[0] < 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void		ft_initialize_array(int *array, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
}

void		ft_array_combn(int *array, int n, int i)
{
	int number;

	if (i == n)
		number = 0;
	else
		number = array[n - i - 1] + 1;
	array[n - i] = number;
	while (array[n - i] <= 10 - i)
	{
		if (i == 1)
			ft_print_array(array, n);
		else
			ft_array_combn(array, n, i - 1);
		array[n - i]++;
	}
}
