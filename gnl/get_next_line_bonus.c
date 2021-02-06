/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:12:19 by hkortbi           #+#    #+#             */
/*   Updated: 2021/01/06 18:18:56 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*get_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' || str[i + 1] == '\0')
	{
		free(str);
		return (NULL);
	}
	while (str[i + j] != '\0')
		j++;
	if (!(remainder = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	j = -1;
	while (str[i + ++j] != '\0')
		remainder[j] = str[(i + 1) + j];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}

static int	free_buffer(char *buffer, int result)
{
	free(buffer);
	buffer = NULL;
	return (result);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*buffer;
	int			r;

	if (!line || fd < 0 || fd > 4864 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	r = 1;
	while (!ft_strchr(str[fd], '\n') && (r = read(fd, buffer, BUFFER_SIZE)) > 0)
		str[fd] = ft_strjoin(str[fd], buffer, r);
	if (r == -1)
		return (free_buffer(buffer, -1));
	free(buffer);
	*line = get_line(str[fd]);
	str[fd] = get_remainder(str[fd]);
	if (r == 0)
		return (free_buffer(str[fd], 0));
	return (1);
}
