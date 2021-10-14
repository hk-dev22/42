/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:45 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:45:36 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_up(t_data *data, int posY, int posX)
{
	posY--;
	if (posY > 0 && data->map2d[posY][posX] != '1')
	{
		if (data->map2d[posY][posX] == 'C')
			data->coin++;
		if (data->map2d[posY][posX] == 'E' && data->coin == data->v_map->coin)
			data->exit = 1;
		else if (data->map2d[posY][posX] == 'E')
			return ;
		data->map2d[posY][posX] = 'P';
		data->map2d[posY + 1][posX] = '0';
		data->move++;
		printf("Number of moves: %d\n", data->move);
	}
}

void	move_right(t_data *data, int posY, int posX)
{
	posX++;
	if (posX < data->v_map->columns && data->map2d[posY][posX] != '1')
	{
		if (data->map2d[posY][posX] == 'C')
			data->coin++;
		if (data->map2d[posY][posX] == 'E' && data->coin == data->v_map->coin)
			data->exit = 1;
		else if (data->map2d[posY][posX] == 'E')
			return ;
		data->map2d[posY][posX] = 'P';
		data->map2d[posY][posX - 1] = '0';
		data->move++;
		printf("Number of moves: %d\n", data->move);
	}
}

void	move_left(t_data *data, int posY, int posX)
{
	posX--;
	if (posX > 0 && data->map2d[posY][posX] != '1')
	{
		if (data->map2d[posY][posX] == 'C')
			data->coin++;
		if (data->map2d[posY][posX] == 'E' && data->coin == data->v_map->coin)
			data->exit = 1;
		else if (data->map2d[posY][posX] == 'E')
			return ;
		data->map2d[posY][posX] = 'P';
		data->map2d[posY][posX + 1] = '0';
		data->move++;
		printf("Number of moves: %d\n", data->move);
	}
}

void	move_down(t_data *data, int posY, int posX)
{
	posY++;
	if (posY < data->v_map->rows && data->map2d[posY][posX] != '1')
	{
		if (data->map2d[posY][posX] == 'C')
			data->coin++;
		if (data->map2d[posY][posX] == 'E' && data->coin == data->v_map->coin)
			data->exit = 1;
		else if (data->map2d[posY][posX] == 'E')
			return ;
		data->map2d[posY][posX] = 'P';
		data->map2d[posY - 1][posX] = '0';
		data->move++;
		printf("Number of moves: %d\n", data->move);
	}
}

void	move_player(t_data *data, char awds)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (i < data->v_map->rows && found == 0)
	{
		j = 0;
		while (j < data->v_map->columns && found == 0)
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
