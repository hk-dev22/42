/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:01 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:50:28 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	malloc_map(t_data *data)
{
	int	i;

	data->map2d = malloc(sizeof(char **) * (data->v_map->rows + 1));
	if (!data->map2d)
		return ;
	ft_bzero(data->map2d, sizeof(char **) * (data->v_map->rows + 1));
	i = 0;
	while (i < data->v_map->rows)
	{
		data->map2d[i] = malloc(sizeof(char *) * data->v_map->columns);
		ft_bzero(data->map2d[i], sizeof(char *) * data->v_map->columns);
		if (!data->map2d[i])
			exit_all(data);
		i++;
	}
}

void	check_map(t_vmap *map, char **map2d)
{
	int	i;
	int	j;

	i = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if ((j == 0 || j == map->columns - 1) && map2d[i][j] != '1')
				map->error = -1;
			else if (map2d[i][j] == 'E')
				map->exit = 1;
			else if (map2d[i][j] == 'C')
				map->coin++;
			else if (map2d[i][j] == 'P')
				map->player = 1;
			else if (map2d[i][j] != '1' && map2d[i][j] != '0')
				map->error = -4;
			j++;
		}
		if (j != map->columns)
			map->error = -2;
		i++;
	}
}

void	map_errors(t_data *data)
{
	if (data->v_map->exit != 1 || data->v_map->coin == 0
		|| data->v_map->player != 1)
		data->v_map->error = -3;
	if (data->v_map->error == -1)
		ft_putstr_fd("Error: map not surrounded completely by walls!", 1);
	if (data->v_map->error == -2)
		ft_putstr_fd("Error: map must be rectangular", 1);
	if (data->v_map->error == -3)
		ft_putstr_fd("Error: map missing one of character!", 1);
	if (data->v_map->error == -4)
		ft_putstr_fd("Error: unknown character!", 1);
}

void	gnl_map2d(t_data *data, int fd)
{
	int		i;
	int		j;
	int		res;
	char	*line;

	res = 1;
	i = 0;
	while (res > 0)
	{
		j = 0;
		res = get_next_line(fd, &line);
		if (line[0] != '\0')
		{
			while (j < data->v_map->columns)
			{
				data->map2d[i][j] = line[j];
				j++;
			}
			i++;
		}
		free(line);
		line = NULL;
	}
	data->map2d[i] = NULL;
}

int	get_map2d(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	malloc_map(data);
	gnl_map2d(data, fd);
	check_map(data->v_map, data->map2d);
	map_errors(data);
	if (!data->map2d)
		return (-1);
	close(fd);
	return (0);
}
