/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:25:31 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/19 12:58:13 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_delimiter(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	int number1;
	int number2;

	number1 = 0;
	while (number1 <= 98)
	{
		number2 = number1 + 1;
		while (number2 <= 99)
		{
			ft_putchar(number1 / 10 + '0');
			ft_putchar(number1 % 10 + '0');
			ft_putchar(' ');
			ft_putchar(number2 / 10 + '0');
			ft_putchar(number2 % 10 + '0');
			if (number1 < 98 && number2 <= 99)
			{
				ft_print_delimiter();
			}
			number2++;
		}
		number1++;
	}
}
