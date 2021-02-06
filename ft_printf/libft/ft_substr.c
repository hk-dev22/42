/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:14:25 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/28 15:03:02 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	size_s;

	if (s == NULL)
		return (NULL);
	size_s = ft_strlen(s);
	if (start >= size_s)
		return (ft_strdup(""));
	substr = (char *)malloc(len * sizeof(*s) + 1);
	if (substr == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
