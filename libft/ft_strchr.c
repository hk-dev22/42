/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:51:50 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/18 20:51:52 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;

	character = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == character)
			return ((char *)s + i);
		i++;
	}
	if (character == '\0')
		return ((char *)s + i);
	else
		return (NULL);
}
