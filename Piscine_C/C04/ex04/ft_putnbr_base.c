/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:23:04 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/26 10:11:39 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);
void	ft_putchar(char c);
int	check_base(char *base);
void ft_convert(int nbr, int size_base, char *base);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int		check_base(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (str[j] != '\0')
		{
			if (i != j && str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_convert(int nbr, int size_base, char *base)
{
	int			div;
	int			mod;
	long int	nb;

	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	div = nb / size_base;
	mod = nb % size_base;
	if (div != 0)
	{
		ft_convert(div, size_base, base);
	}
	ft_putchar(base[mod]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_base(base) == 0)
		return ;
	ft_convert(nbr, ft_strlen(base), base);
}
