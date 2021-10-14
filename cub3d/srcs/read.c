/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:11:35 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/27 23:53:18 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

// First read of the file, check if the file is opening
void    first_read(t_data *data, char *file)
{
    int fd;
    int gnl;
    char *line;
    int tmp;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        ft_putstr_fd("Error, opening map file", 1);
    gnl = 1;
    while (gnl)
    {
        gnl = get_next_line(fd, &line);
		// Read map
		if (line[0] == '0' || line [0] == '1')
		{
			tmp = ft_strlen(line);
            printf("%s\n", line);
			if (tmp > data->vmap->columns)
				data->vmap->columns = tmp;
			data->vmap->rows++;
		}
        free(line);
    }
    close(fd);
}