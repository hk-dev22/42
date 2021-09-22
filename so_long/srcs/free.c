/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:56:02 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/22 18:35:51 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    free_map2d(char **map2d)
{
    int i;

	i = 0;
	while (map2d[i])
	{
        if (map2d[i])
            free(map2d[i]);
        i++;
    }
    if (map2d)
	    free(map2d);
}


void    free_data(t_data *data)
{
    if (data->mlx_ptr)
        free(data->mlx_ptr);
    // if (data->mlx_win)
    //     free(data->mlx_win);
    if (data->valid_map)
        free(data->valid_map);
    if (data->map2d)
        free_map2d(data->map2d);
    if (data->img_coin)
        free(data->img_coin);
    if (data->img_door)
        free(data->img_door);
    if (data->img_floor)
        free(data->img_floor);
    if (data->img_player)
        free(data->img_player);
    if (data->img_space)
        free(data->img_space);
    if (data->img_wall)
        free(data->img_wall);
    if (data)
        free(data);
}

void exit_all(t_data *data)
{
	if (data)
		free_data(data);
	exit(0);
}

int	handle_close(t_data *data)
{
	if (data->img_floor->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_floor->mlx_img);
	if (data->img_wall->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_wall->mlx_img);
	if (data->img_player->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_player->mlx_img);
	if (data->img_door->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_door->mlx_img);
	if (data->img_coin->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_coin->mlx_img);
	if (data->img_space->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_space->mlx_img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free_data(data);
	exit(EXIT_FAILURE);
}