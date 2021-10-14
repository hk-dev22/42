/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:38:45 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/28 16:04:54 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;

	if (!dest && !src)
		return (NULL);
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	if (source <= destination)
		while (n--)
			destination[n] = source[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
