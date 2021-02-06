/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:15:56 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/15 08:45:06 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char chiffre;

	chiffre = '0';
	while (chiffre <= '9')
	{
		write(1, &chiffre, 1);
		chiffre++;
	}
}
