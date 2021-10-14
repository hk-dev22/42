/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:27:25 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/19 00:08:23 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		ft_lenword(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static	void	*ft_splitfree(char **split, int line)
{
	int i;

	i = 0;
	while (i <= line)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char		**ft_splitfill(char const *s, char c, int words, char **split)
{
	int i;
	int j;
	int index;
	int size_w;

	i = -1;
	j = 0;
	while (++i < words)
	{
		while (s[j] == c)
			j++;
		if (s[j] == '\0')
			break ;
		size_w = ft_lenword(s + j, c) + 1;
		if (!(split[i] = (char *)malloc(sizeof(char) * size_w)))
			return (ft_splitfree(split, i));
		index = 0;
		while (s[j] != '\0' && s[j] != c)
			split[i][index++] = s[j++];
		split[i][index] = '\0';
	}
	split[i] = NULL;
	return (split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		lines;

	if (!s)
		return (NULL);
	lines = ft_countwords(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (lines + 1))))
		return (NULL);
	split = ft_splitfill(s, c, lines, split);
	return (split);
}
