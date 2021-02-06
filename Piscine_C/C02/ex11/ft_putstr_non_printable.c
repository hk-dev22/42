/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:12:15 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/22 11:44:22 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_init_hexarray(int decimal);
char	*ft_strlowcase(char *str);
void	ft_putstr(char *str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;
	int decimal;

	decimal = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
		{
			decimal = str[i];
			ft_init_hexarray(decimal);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

void	ft_init_hexarray(int decimal)
{
	int		temp;
	char	hex[2];
	int		i;

	i = 0;
	temp = 0;
	while (decimal)
	{
		temp = decimal % 16;
		if (temp < 10)
			hex[i] = '0' + temp;
		else
			hex[i] = 'A' + (temp - 10);
		decimal = decimal / 16;
		i++;
	}
	ft_strlowcase(hex);
	write(1, "\\", 1);
	if (i == 1)
		write(1, "0", 1);
	ft_putstr(hex);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 98)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
