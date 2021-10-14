/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:40:19 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/01 19:15:25 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	load_image(t_data *data, t_img *img, char *path)
{
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &(img->width), &(img->height));
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
}

t_data *init_data()
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    data->mlx_ptr = NULL;
    data->mlx_win = NULL;
    data->img_space = init_img();
    // data->img_wall = init_img();
    // data->img_floor = init_img();
    // data->img_player = init_img();
    data->ray = init_ray();
    data->map2d = NULL;
    data->vmap = init_vmap();
    data->player = init_player();
    if (!data || !data->img_space || !data->vmap || !data->player || !data->ray)
    {
        ft_putstr_fd("Error: memory allocation!\n", 1);
        exit_all(data);
    }
    return (data);
}

void    init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "CUB3D");

    data->img_space->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->img_space->addr = mlx_get_data_addr(data->img_space->mlx_img, &data->img_space->bpp, &data->img_space->line_len, &data->img_space->endian);

    // load_image(data, data->img_floor, "./textures/floor.xpm");
    //load_image(data, data->img_wall, "./textures/bricks.xpm");
    // load_image(data, data->img_player, "./textures/knight.xpm");
    get_texture(data);

    data->player->posX = 22;
    data->player->posY = 12;  //x and y start position
    data->player->dirX = -1, data->player->dirY = 0; //initial direction vector
    data->player->planeX = 0, data->player->planeY = 0.66; //the 2d raycaster version of camera plane
}