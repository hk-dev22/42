/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:14:51 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/25 14:47:49 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int n, char **matrix)
{
	int i;
	int swap;

	i = 1;
	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 1;
		while (i < n - 1)
		{
			if (ft_strcmp(matrix[i], matrix[i + 1]) > 0)
			{
				ft_swap(&matrix[i], &matrix[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 2)
		ft_sort_params(argc, argv);
	while (i <= argc - 1)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
