/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:01 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/29 15:20:38 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    malloc_map(t_data *data)
{
    int i;

    data->map2d = malloc(sizeof(char **) * (data->vmap->rows + 1));
    if (!data->map2d)
        return ;
    ft_bzero(data->map2d, sizeof(char **) * (data->vmap->rows + 1));
    i = 0;
    while (i < data->vmap->rows)
    {
        data->map2d[i] = malloc(sizeof(char *) * data->vmap->columns);
        ft_bzero(data->map2d[i], sizeof(char *) * data->vmap->columns);
        if (!data->map2d[i])
            exit_all(data);
        i++;
    }
}

void    gnl_map2d(t_data *data, int fd)
{
    int i;
    int j;
    int res;
    char * line;

    res = 1;
    i = 0;
    while (res > 0)
    {   
        j = 0;
        res = get_next_line(fd, &line);
        if (line[0] != '\0')
        {
            while (j <data->vmap->columns)
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

int    get_map2d(t_data *data, char *file)
{
    int	fd;

    fd = open(file, O_RDONLY);
    malloc_map(data);
    gnl_map2d(data, fd);
    if (!data->map2d)
        return (-1);
    close(fd);
    return (0);
}