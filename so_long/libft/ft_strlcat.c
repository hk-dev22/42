/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:24:04 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/08 00:51:43 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_d;
	unsigned int	size_s;

	i = 0;
	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	if (size <= size_d)
		return (size + size_s);
	j = size_d;
	while (src[i] != '\0' && i + j < size - 1)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (size_s + size_d);
}
