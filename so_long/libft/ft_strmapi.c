/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:17:07 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/28 16:06:03 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	size_s;
	int				i;

	if (!s || !f)
		return (NULL);
	size_s = ft_strlen(s);
	strmapi = (char *)malloc(sizeof(*s) * size_s + 1);
	if (!strmapi || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[i] = '\0';
	return (strmapi);
}
