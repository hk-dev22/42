/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:36:43 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/01 19:01:43 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/cub3d.h"

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
    if (data->vmap)
        free(data->vmap);
    if (data->map2d)
        free_map2d(data->map2d);
    if (data->img_space)
        free(data->img_space);
    if (data->player)
        free(data->player);
    if (data->ray)
        free(data->ray);
    if (data)
        free(data);
}

void exit_all(t_data *data)
{
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

int	handle_close(t_data *data)
{
	if (data->img_space->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img_space->mlx_img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free_data(data);
	exit(EXIT_FAILURE);
}
