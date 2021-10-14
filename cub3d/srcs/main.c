/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:08:50 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/01 19:04:38 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/cub3d.h"

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_close(data);
	move_player(data, keysym);
	return (SUCCESS);
}


int	render(t_data *data)
{

	clear_background(data->img_space);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_space->mlx_img, 0, 0);
	return (SUCCESS);
}

int	check_arg(char *file)
{
	int found;
	char *search;

	found = 1;
	search = ft_strrchr(file, '.');
	if (search)
	{
		found = ft_strncmp(search, ".cub", 4);
		if (found == 0)
			return (0);
	}
	else
		ft_putstr_fd("Error: wrong file type!\n", 1);
	return (-1);
}

int	main(int ac, char **av)
{
	t_data *data;

	if (ac !=2)
	{
		ft_putstr_fd("Error, wrong number of arguments (2)", 1);
		return (-1);
	}
	if (check_arg(av[1]) == -1)
		return (-1);
	data = init_data();
	first_read(data, av[1]);
	if ((get_map2d(data, av[1])) == 0)
	{
		init_game(data);
		/* Setup hooks */ 
		mlx_loop_hook(data->mlx_ptr, &render, data);
		mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
		mlx_hook(data->mlx_win, ClientMessage, LeaveWindowMask, &handle_close, data);
		mlx_loop(data->mlx_ptr);
		exit(SUCCESS);
	}
}