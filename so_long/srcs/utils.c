/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:39:24 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:39:59 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	first_read(t_data *data, char *file)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error, opening map file", 1);
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (data->v_map->columns == 0)
			data->v_map->columns = ft_strlen(line);
		if (line[0])
			data->v_map->rows++;
		free(line);
	}
	close(fd);
}

void	check_move(t_data *data, char awds, int posY, int posX)
{
	if (awds == 'A')
		move_left(data, posY, posX);
	if (awds == 'S')
		move_down(data, posY, posX);
	if (awds == 'D')
		move_right(data, posY, posX);
	if (awds == 'W')
		move_up(data, posY, posX);
}
