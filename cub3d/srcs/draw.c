/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:15:51 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/01 16:35:49 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_len + (x * \
						(img->bpp / 8)))));
}

void	set_pixel(t_img *img, int x, int y, int color)
{
	*(unsigned int *)(img->addr + (y * img->line_len + x * \
				(img->bpp / 8))) = color;
}

void	draw_on_img(t_img *img, t_img *s_img, int startX, int startY, int bpp)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < bpp)
	{
		draw.y = 0;
		while (draw.y < bpp)
		{
			//Get the pixel color of the s_img
			draw.r_x = (float)draw.x / (float)bpp;
			draw.r_y = (float)draw.y / (float)bpp;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			//Draw the pixel color
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			if (draw.color != (int)BLACK)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int draw_vline(t_img *img, int x, int drawStart, int drawEnd, int color)
{
    int i;

    i = drawStart;
    while (i < drawEnd)
        img_pix_put(img, x, i++, color);
    return (0);
}

int draw_vline2(t_data *data, int x, int drawStart, int drawEnd, int color)
{
	int i;

    i = drawStart;
	while (i < drawEnd)
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, i++, color);
    return (0);
}

void	clear_background(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			img_pix_put(img, j++, i, BLACK_PIXEL);
		}
		++i;
	}
}

// void    draw_minimap(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     while (data->map2d[i])
//     {
//         j = 0;
//         while (data->map2d[i][j])
//         {
//             if (data->map2d[i][j] == '1')
//                 draw_on_img(data->img_space, data->img_wall, j * m,  i * m, m);
//             else
//                 draw_on_img(data->img_space, data->img_floor, j * m,  i * m, m);
//             if (data->map2d[i][j] == 'N')
//             {
//                 data->player->x = j;
//                 data->player->y = i;
//             }
//             j++;
//         }
//         i++;
//     }
//     draw_miniplayer(data);
// }

// void    draw_miniplayer(t_data *data)
// {
//     draw_on_img(data->img_space, data->img_player, data->player->x * m + m / 2, data->player->y * m + m / 2 , m / 4);
// }