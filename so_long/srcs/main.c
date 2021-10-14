/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:37:32 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:52:53 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		closer(data);
	if (keysym == XK_a)
		move_player(data, 'A');
	if (keysym == XK_d)
		move_player(data, 'D');
	if (keysym == XK_w)
		move_player(data, 'W');
	if (keysym == XK_s)
		move_player(data, 'S');
	if (data->exit == 1)
		closer(data);
	return (SUCCESS);
}

int	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->mlx_img, 0, 0);
	draw_map(data);
	return (SUCCESS);
}

int	check_arg(char *file)
{
	int		found;
	char	*search;

	found = 1;
	search = ft_strrchr(file, '.');
	if (search)
	{
		found = ft_strncmp(search, ".ber", 4);
		if (found == 0)
			return (0);
	}
	else
		ft_putstr_fd("Error: wrong file type!\n", 1);
	return (-1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments (2)!", 1);
		return (-1);
	}
	if (check_arg(av[1]) == -1)
		return (-1);
	data = init_data();
	first_read(data, av[1]);
	if ((get_map2d(data, av[1])) == 0 && data->v_map->error == 0)
	{
		init_game(data);
		mlx_loop_hook(data->mlx_ptr, &render, data);
		mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &keypress, data);
		mlx_hook(data->mlx_win, ClientMessage, LeaveWindowMask, &closer, data);
		mlx_loop(data->mlx_ptr);
		exit(SUCCESS);
	}
	else
		exit_all(data);
	return (0);
}
