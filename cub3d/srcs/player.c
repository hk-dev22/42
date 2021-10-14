/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:15:00 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/30 15:38:05 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void    move_player(t_data *data, int keysym)
{
    double moveSpeed = 0.5; ///la constante est en squares/second
    double rotSpeed = M_PI / 6; ///la constante est en in radians/second
    double oldDirX;
    double oldPlaneX;
    if (keysym == XK_w)
    {
        if(data->map2d[(int)(data->player->posX + data->player->dirX * moveSpeed)][(int)(data->player->posY)] == '0') 
            data->player->posX += data->player->dirX * moveSpeed ;
        if(data->map2d[(int)(data->player->posX)][(int)(data->player->posY + data->player->dirY * moveSpeed)] == '0') 
            data->player->posY += data->player->dirY * moveSpeed ;
    }
    if (keysym == XK_s)
    {
        if(data->map2d[(int)(data->player->posX - data->player->dirX * moveSpeed)][(int)(data->player->posY)] == '0') 
            data->player->posX -= data->player->dirX * moveSpeed;
        if(data->map2d[(int)(data->player->posX)][(int)(data->player->posY - data->player->dirY * moveSpeed)] == '0') 
            data->player->posY -= data->player->dirY * moveSpeed;
    }
    if (keysym == XK_a)
    { 
       ///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
      oldDirX = data->player->dirX;
      data->player->dirX = data->player->dirX * cos(rotSpeed) - data->player->dirY * sin(rotSpeed);
      data->player->dirY = oldDirX * sin(rotSpeed) + data->player->dirY * cos(rotSpeed);
      oldPlaneX = data->player->planeX;
      data->player->planeX = data->player->planeX * cos(rotSpeed) - data->player->planeY * sin(rotSpeed);
      data->player->planeY = oldPlaneX * sin(rotSpeed) + data->player->planeY * cos(rotSpeed);
    }
    if (keysym == XK_d)
    {
        ///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
      oldDirX = data->player->dirX;
      data->player->dirX = data->player->dirX * cos(-rotSpeed) - data->player->dirY * sin(-rotSpeed);
      data->player->dirY = oldDirX * sin(-rotSpeed) + data->player->dirY * cos(-rotSpeed);
      oldPlaneX = data->player->planeX;
      data->player->planeX = data->player->planeX * cos(-rotSpeed) - data->player->planeY * sin(-rotSpeed);
      data->player->planeY = oldPlaneX * sin(-rotSpeed) + data->player->planeY * cos(-rotSpeed);
    }
}