/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:00:45 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/28 13:00:15 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		*destination;

	if (!dest && !src)
		return (NULL);
	i = 0;
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
