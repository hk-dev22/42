/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:37:32 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/22 19:58:30 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_close(data);
	if (keysym == XK_a)
		move_player(data, 'A');
	if (keysym == XK_d)
		move_player(data, 'D');
	if (keysym == XK_w)
		move_player(data, 'W');
	if (keysym == XK_s)
		move_player(data, 'S');
	return (SUCCESS);
}


int	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_space->mlx_img, 0, 0);
	draw_map(data);
	return (SUCCESS);
}

int main(int ac, char ** av)
{
	t_data *data;

	if (ac != 2)
	{
		ft_putstr_fd("Wrong number of arguments (2)!", 1);
		return (-1);
	}
	data = init_data();
	if ((first_read(data, av[1]) != -1))
	{
		if ((get_map2d(data, av[1])) != 0)
			exit_all(data);
		if (data->valid_map->error != 0)
			exit_all(data);
		init_game(data);

		/* Setup hooks */ 
		mlx_loop_hook(data->mlx_ptr, &render, data);
		mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
		mlx_hook(data->mlx_win, ClientMessage, LeaveWindowMask, &handle_close, data);
		mlx_loop(data->mlx_ptr);
		exit(SUCCESS);
	}
	else
		exit_all(data);
	return (0);
}



