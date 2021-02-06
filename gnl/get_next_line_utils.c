/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:11:15 by hkortbi           #+#    #+#             */
/*   Updated: 2021/01/06 17:03:45 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dup;

	size = ft_strlen(s);
	dup = (char *)malloc(size * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
		{
			dup[i] = s[i];
			i++;
		}
	}
	dup[i] = '\0';
	return (dup);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2, int bytes_read)
{
	char	*join;
	int		i_d;
	int		i_s;
	int		size_s1;

	i_d = 0;
	i_s = 0;
	size_s1 = ft_strlen(s1);
	if (!(join = malloc(sizeof(char) * (size_s1 + bytes_read + 1))))
		return (NULL);
	while (0 < size_s1--)
		join[i_d++] = s1[i_s++];
	i_s = 0;
	while (0 < bytes_read--)
		join[i_d++] = s2[i_s++];
	join[i_d] = '\0';
	free(s1);
	return (join);
}
