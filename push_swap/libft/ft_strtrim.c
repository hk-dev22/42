/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:29:23 by hkortbi           #+#    #+#             */
/*   Updated: 2020/11/28 15:07:46 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_begin(char const *s1, char const *set)
{
	int i;
	int j;
	int found;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static int		ft_end(char const *s1, char const *set)
{
	int size_s1;
	int i;
	int found;
	int j;

	size_s1 = ft_strlen(s1);
	i = size_s1 - 1;
	while (i >= 0)
	{
		j = 0;
		found = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 1)
			i--;
		else
			break ;
	}
	if (i < 0)
		i = size_s1;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = ft_begin(s1, set);
	end = ft_end(s1, set);
	if (!(strtrim = (char *)malloc((end - start) * sizeof(*s1) + 2)))
		return (NULL);
	i = 0;
	while (start <= end)
	{
		strtrim[i] = s1[start];
		i++;
		start++;
	}
	strtrim[i] = '\0';
	return (strtrim);
}
