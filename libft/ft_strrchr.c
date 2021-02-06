/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:07:55 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/18 21:07:57 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	character;
	char	*p;

	character = (char)c;
	p = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == character)
			p = (char *)s + i;
		i++;
	}
	if (character == '\0')
		p = (char *)s + i;
	return (p);
}
