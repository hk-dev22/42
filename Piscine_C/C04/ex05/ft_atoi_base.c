/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:41:22 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/26 10:18:27 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_power(int nbr, int power);
int check_base(char *str);
int ft_strlen(char *str);
int ft_basei(char c, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int decimal;
	int i;
	int size;
	int minus;

	size = ft_strlen(str) - 1;
	i = 0;
	minus = 1;
	decimal = 0;
	if (check_base(base) == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		minus = (str[i] == '-') ? -minus : minus;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_basei(str[i], base) == -1)
			return (0);
		decimal += ft_basei(str[i++], base) * ft_power(ft_strlen(base), size--);
	}
	return (minus * decimal);
}

int	ft_basei(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_power(int nbr, int power)
{
	int result;

	result = nbr;
	if (power == 0)
		result = 1;
	while (power > 1)
	{
		result *= nbr;
		power--;
	}
	return (result);
}

int	check_base(char *str)
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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
