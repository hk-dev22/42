/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:44:34 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:50:53 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	get_pixel(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_len + (x * \
						(img->bpp / 8)))));
}

static void	set_pixel(t_img *img, int x, int y, int color)
{
	*(unsigned int *)(img->addr + (y * img->line_len + x * \
				(img->bpp / 8))) = color;
}

void	draw_on_img(t_img *img, t_img *s_img, int startX, int startY)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < M)
	{
		draw.y = 0;
		while (draw.y < M)
		{
			draw.r_x = (float)draw.x / (float)M;
			draw.r_y = (float)draw.y / (float)M;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			if (draw.color != (int)BLACK)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

void	draw_character(t_data *data, int i, int j)
{
	if (data->map2d[i][j] == 'E')
	{
		draw_on_img(data->img, data->img_floor, j * M, i * M);
		draw_on_img(data->img, data->img_door, j * M, i * M);
	}
	if (data->map2d[i][j] == 'P')
	{
		draw_on_img(data->img, data->img_floor, j * M, i * M);
		draw_on_img(data->img, data->img_player, j * M, i * M);
	}
	if (data->map2d[i][j] == 'C')
	{
		draw_on_img(data->img, data->img_floor, j * M, i * M);
		draw_on_img(data->img, data->img_coin, j * M, i * M);
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == '1')
				draw_on_img(data->img, data->img_wall, j * M, i * M);
			if (data->map2d[i][j] == '0')
				draw_on_img(data->img, data->img_floor, j * M, i * M);
			else
				draw_character(data, i, j);
			j++;
		}
		i++;
	}
}
