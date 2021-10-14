/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:52:53 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:53:53 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_image(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &(img->width),
			&(img->height));
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

t_img	*init_img(void)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
	img->line_len = 0;
	return (img);
}

t_vmap	*init_vmap(void)
{
	t_vmap	*vmap;

	vmap = (t_vmap *)malloc(sizeof(t_vmap));
	vmap->coin = 0;
	vmap->columns = 0;
	vmap->error = 0;
	vmap->exit = 0;
	vmap->rows = 0;
	vmap->player = 0;
	return (vmap);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->img = init_img();
	data->map2d = NULL;
	data->v_map = init_vmap();
	data->img_floor = init_img();
	data->img_wall = init_img();
	data->img_door = init_img();
	data->img_coin = init_img();
	data->img_player = init_img();
	data->coin = 0;
	data->exit = 0;
	data->move = 0;
	if (!data || !data->img || !data->img_wall || !data->img_floor
		|| !data->img_door || !data->img_player || !data->img_coin
		|| !data->v_map)
	{
		ft_putstr_fd("Error: memory allocation!\n", 1);
		exit_all(data);
	}
	return (data);
}

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->v_map->columns * M,
			data->v_map->rows * M, "SO_LONG");
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, data->v_map->columns * M,
			data->v_map->rows * M);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	load_image(data, data->img_floor, "./textures/floor.xpm");
	load_image(data, data->img_wall, "./textures/brick_black.xpm");
	load_image(data, data->img_door, "./textures/ladder.xpm");
	load_image(data, data->img_coin, "./textures/gold_coin.xpm");
	load_image(data, data->img_player, "./textures/knight.xpm");
}
