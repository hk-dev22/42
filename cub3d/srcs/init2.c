/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:21:04 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/01 15:37:24 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_ray   *init_ray(void)
{
    t_ray *ray;

    ray = (t_ray *)malloc(sizeof(t_ray));
    ray->cameraX = 0;
    ray->rayDirX = 0;
    ray->rayDirY = 0;
    ray->mapX = 0;
    ray->mapY = 0;
    ray->sideDistX = 0;
    ray->sideDistY = 0;
    ray->deltaDistX = 0;
    ray->deltaDistY = 0;
    ray->stepX = 0;
    ray->stepY = 0;
    ray->sideHV = 0;
    ray->texX = 0;
    ray->texY = 0;
    ray->texStep = 0;
    return (ray);
}

t_player *init_player(void)
{
    t_player *player;

    player = (t_player *)malloc(sizeof(t_player));
    player->posX = 0;
    player->posY = 0;
    player->dirX = 0;
    player->dirY = 0;
    player->planeX = 0;
    player->planeY = 0;
    return (player);
}

t_vmap *init_vmap(void)
{
    t_vmap *vmap;

    vmap = (t_vmap *)malloc(sizeof(t_vmap));
    vmap->collectible = 0;
    vmap->columns = 0;
    vmap->error = 0;
    vmap->exit = 0;
    vmap->rows = 0;
    vmap->starting_position = 0;
    return (vmap);
}

t_img    *init_img(void)
{
    t_img *img;

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