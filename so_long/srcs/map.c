/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:01 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/22 21:18:30 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    malloc_map(t_data *data)
{
    int i;

    data->map2d = malloc(sizeof(char **) * (data->valid_map->rows + 1));
    if (!data->map2d)
        return ;
    ft_bzero(data->map2d, sizeof(char **) * (data->valid_map->rows + 1));
    i = 0;
    while (i < data->valid_map->rows)
    {
        data->map2d[i] = malloc(sizeof(char *) * data->valid_map->columns);
        ft_bzero(data->map2d[i], sizeof(char *) * data->valid_map->columns);
        if (!data->map2d[i])
            exit_all(data);
        i++;
    }
}

void	check_map(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			// The maps must be closed/surrounded by walls
			if ((j == 0 || j == data->valid_map->columns - 1) && data->map2d[i][j] != '1')
				data->valid_map->error = -1;
			if (data->map2d[i][j] == 'E')
				data->valid_map->exit = 1;
			if (data->map2d[i][j] == 'C')
				data->valid_map->collectible++;
			if (data->map2d[i][j] == 'P')
				data->valid_map->starting_position = 1;
			j++;
		}
		// The map must be rectangular
		if (j != data->valid_map->columns)
			data->valid_map->error = -2;
		i++;
	}
	// Map must have at least one exit, one collectible, and one starting position
	if (data->valid_map->exit != 1 || data->valid_map->collectible == 0 || data->valid_map->starting_position != 1)
		data->valid_map->error = -3;
	map_errors(data->valid_map->error);
}

void	map_errors(int error)
{
	if (error == -1)
		ft_putstr_fd("Error: map not surrounded completely by walls!", 1);
	if (error == -2)
		ft_putstr_fd("Error: map must be rectangular", 1);
	if (error == -3)
		ft_putstr_fd("Error: map must have at least one exit, one collectible, and one starting position!", 1);
	
}

int    get_map2d(t_data *data, char *file)
{
    int	fd;
	char *line;
    int i;
    int j;
    int res;

    fd = open(file, O_RDONLY);
    malloc_map(data);
    i = 0;
    res = 1;
	while (res > 0)
    {   
        j = 0;
        res = get_next_line(fd, &line);
        if (line[0] != '\0')
        {
            while (j <data->valid_map->columns)
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
    check_map(data);
    if (!data->map2d)
        return (-1);
    close(fd);
    return (0);
}