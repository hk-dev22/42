/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:44:15 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/28 13:07:18 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	else
	{
		i = 0;
		while (i < nmemb * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return ((void *)ptr);
}
