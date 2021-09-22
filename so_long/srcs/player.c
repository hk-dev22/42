/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:45 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/22 21:16:01 by hkortbi          ###   ########.fr       */
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
		if (data->map2d[posY][posX] == 'E' && data->coin == data->valid_map->collectible)
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
	if (posX < data->valid_map->columns && data->map2d[posY][posX] != '1')
	{
		if (data->map2d[posY][posX] == 'C')
			data->coin++;
		if (data->map2d[posY][posX] == 'E' && data->coin == data->valid_map->collectible)
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
		if (data->map2d[posY][posX] == 'E' && data->coin == data->valid_map->collectible)
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
	if (posY < data->valid_map->rows && data->map2d[posY][posX] != '1')
	{
		if (data->map2d[posY][posX] == 'C')
			data->coin++;
		if (data->map2d[posY][posX] == 'E' && data->coin == data->valid_map->collectible)
			data->exit = 1;
		else if (data->map2d[posY][posX] == 'E')
			return ;
		data->map2d[posY][posX] = 'P';
		data->map2d[posY - 1][posX] = '0';
		data->move++;
		printf("Number of moves: %d\n", data->move);
	}
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