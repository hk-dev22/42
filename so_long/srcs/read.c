/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:02:12 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/22 18:39:28 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


// First read of the file, check if the file is opening and if the map is rectangular before malloc map
int    first_read(t_data *data, char *file)
{
    int fd;
    int gnl;
    char *line;
    int map_rectangular;
    int temp_c;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        ft_putstr_fd("Error, opening map file", 1);
    gnl = 1;
    temp_c = 0;
    map_rectangular = 0;
    while (gnl)
    {
        gnl = get_next_line(fd, &line);
        if (line[0])
        {
            data->valid_map->columns = ft_strlen(line);
            if (data->valid_map->rows != 0 && temp_c != data->valid_map->columns)
                map_rectangular = -1;
            temp_c = data->valid_map->columns;
            data->valid_map->rows++;
        }
        free(line);
    }
    close(fd);
    return (map_rectangular);
}
