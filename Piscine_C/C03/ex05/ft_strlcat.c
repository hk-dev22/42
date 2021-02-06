/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 11:45:51 by hkortbi           #+#    #+#             */
/*   Updated: 2020/10/22 10:41:19 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int size_d;
	unsigned int size_s;

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
