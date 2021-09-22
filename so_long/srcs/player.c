/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:45 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/22 19:57:36 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_move(t_data *data, char awds, int posY, int posX)
{

	if (awds == 'D')
	{
		posX++;
		if (posX < data->valid_map->columns && data->map2d[posY][posX] != '1')
		{
			data->map2d[posY][posX] = 'P';
			data->map2d[posY][posX - 1] = '0';
		}
	}
	if (awds == 'A')
	{
		posX--;
		if (posX > 0 && data->map2d[posY][posX] != '1')
		{
			data->map2d[posY][posX] = 'P';
			data->map2d[posY][posX + 1] = '0';
		}
	}
	if (awds == 'W')
	{
		posY--;
		if (posY > 0 && data->map2d[posY][posX] != '1')
		{
			data->map2d[posY][posX] = 'P';
			data->map2d[posY + 1][posX] = '0';
		}
	}
	if (awds == 'S')
	{
		posY++;
		if (posY < data->valid_map->rows && data->map2d[posY][posX] != '1')
		{
			data->map2d[posY][posX] = 'P';
			data->map2d[posY - 1][posX] = '0';
		}
	}
}

void	move_player(t_data *data, char awds)
{
	int i;
	int j;
	int	found;

	found = 0;
	i = 0;
	while (i < data->valid_map->rows && found == 0)
	{
		j = 0;
		while (j < data->valid_map->columns && found == 0)
		{
			if (data->map2d[i][j] == 'P')
			{
				check_move(data, awds, i, j);
				found = 1;
			}
			j++;
		}
		i++;
	}
}