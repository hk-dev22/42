/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:16:56 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/02 13:11:42 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"


void	get_texture(t_data *data)
{
	data->textures[0].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/floor.xpm", &(data->textures[0].width), &(data->textures[0].height));
	data->textures[0].addr = mlx_get_data_addr(data->textures[0].mlx_img, &data->textures[0].bpp, &data->textures[0].line_len, &data->textures[0].endian);
}

void	init_raycasting(t_data *data, int x)
{
	///calcul de la position et de l'orientation du rayon
	data->ray->cameraX = 2 * x / (double)(WIDTH) - 1; ///Coordonner x dans l'espace de la camera
	data->ray->rayDirX = data->player->dirX + data->player->planeX * data->ray->cameraX;
	data->ray->rayDirY = data->player->dirY + data->player->planeY * data->ray->cameraX;
	///Dans quelle case de la carte, nous nous situons au debut
	data->ray->mapX = (int)(data->player->posX);
	data->ray->mapY = (int)(data->player->posY);
	///Longueur des rayons de la position  du x ou y actuel au prochain x ou y
	data->ray->deltaDistX = sqrt(1 + (data->ray->rayDirY * data->ray->rayDirY) / (data->ray->rayDirX * data->ray->rayDirX)); ///Distance entre deux murs verticaux
	data->ray->deltaDistY = sqrt(1 + (data->ray->rayDirX * data->ray->rayDirX) / (data->ray->rayDirY * data->ray->rayDirY)); ///Distance entre deux murs horizontaux
} 

void	sideDist(t_data *data)
{
	///Etape du prochain mouvement
	///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur vertical le plus proche en fonction de la prochaine etape x
	if (data->ray->rayDirX < 0) /// Si le rayon est oriente vers la gauche
	{
		data->ray->stepX = -1;
		data->ray->sideDistX = (data->player->posX - data->ray->mapX) * data->ray->deltaDistX; ///  On calcule la distance entre joueur et 1e prochain mur vertical
	}
	else ///Si le rayon est oriente vers la droite
	{
		data->ray->stepX = 1;
		data->ray->sideDistX = (data->ray->mapX + 1.0 - data->player->posX) * data->ray->deltaDistX; /// On calcule la distance entre joueur et 1e prochain mur vertical
	}
	///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur horizontal le plus proche en fonction de la prochaine etape y
	if (data->ray->rayDirY < 0)
	{
		data->ray->stepY = -1;///  On recule
		data->ray->sideDistY = (data->player->posY - data->ray->mapY) * data->ray->deltaDistY;///  On calcule la distance entre le joueur et 1e prochain mur horizontal
	}
	else
	{
		data->ray->stepY = 1;///  On avance
		data->ray->sideDistY = (data->ray->mapY + 1.0 - data->player->posY) * data->ray->deltaDistY;/// On calcule la distance entre joueur et 1e prochain mur horizontal
	}
}

void	dda(t_data *data)
{
	int hit; ///Y a-t-il un mur de detecter?

	hit = 0;
	///lance de DDA = Digital Differential Analysis (algorithme de detection des murs)
	while (hit == 0)
	{
		///Saute au prochain carre de la map soit vers la  direction x, soit vers la direction y en fonction du mur le plus proche
		if (data->ray->sideDistX < data->ray->sideDistY)
		{
			data->ray->sideDistX += data->ray->deltaDistX;
			data->ray->mapX += data->ray->stepX;
			data->ray->sideHV = 0; ///Mur vertical
		}
		else
		{
			data->ray->sideDistY += data->ray->deltaDistY;
			data->ray->mapY += data->ray->stepY;
			data->ray->sideHV = 1; ///Mur horizontal
		}
		///Verifier si le rayon a detecte un mur
		if (data->map2d[data->ray->mapX][data->ray->mapY] == '1') 
			hit = 1;
	}
}

void	wall_projection(t_data *data)
{
	///Calcul de la distance projetee sur la direction de la camera (La distance oblique donnera un effet fisheye !)
	if (data->ray->sideHV == 0)
		//data->ray->perpWallDist = data->ray->sideDistX - data->ray->deltaDistX;
		data->ray->perpWallDist = fabs((data->ray->mapX - data->player->posX + (1 - data->ray->stepX) / 2) / data->ray->rayDirX);
	else
		data->ray->perpWallDist = fabs((data->ray->mapY - data->player->posY + (1 - data->ray->stepY) / 2) / data->ray->rayDirY);
	///Calculer la hauteur de la ligne appelee a l'ecran
	data->ray->lineHeight = abs((int)(HEIGHT / data->ray->perpWallDist));
	///Calculer le plus bas et le plus eleve des pixels a remplir dans la bande actuelle
	data->ray->drawStart = -data->ray->lineHeight / 2 + HEIGHT / 2;
	if(data->ray->drawStart < 0)
		data->ray->drawStart = 0;
	data->ray->drawEnd = data->ray->lineHeight / 2 + HEIGHT / 2;
	if(data->ray->drawEnd >= HEIGHT)
		data->ray->drawEnd = HEIGHT - 1;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	set_tex(t_data *data, t_img *img_wall)
{
	if (data->ray->sideHV == 0)
		data->ray->wallX = data->player->posY + data->ray->perpWallDist * data->ray->rayDirY;
	else
		data->ray->wallX = data->player->posX + data->ray->perpWallDist * data->ray->rayDirX;
	data->ray->wallX -= floor((data->ray->wallX));
	data->ray->texX = (int)(data->ray->wallX * (double)img_wall->width);
	if ((data->ray->sideHV == 0 && data->ray->rayDirX > 0) || (data->ray->sideHV == 1 && data->ray->rayDirY < 0))
		data->ray->texX = img_wall->width - data->ray->texX - 1;
	data->ray->texY = 0;
	data->ray->texStep = img_wall->height / (double)data->ray->lineHeight;
	return (0);
}

int	draw_tex(t_data *data, int x)
{
	int		y;

	set_tex(data, &data->textures[0]);
	y = data->ray->drawStart - 1;
	double texPos = (data->ray->drawStart - HEIGHT / 2 + data->ray->lineHeight / 2) * data->ray->texStep;
	while (++y <= data->ray->drawEnd)
	{
		data->ray->texY =(int)texPos & (data->textures[0].height - 1);
		texPos += data->ray->texStep;
		// color =  get_pixel(&data->textures[0], data->ray->texX, data->ray->texY);
		// set_pixel(data->img_space, x, y, color);
		if (y < HEIGHT && x < WIDTH)
			data->img_space->addr[y * data->img_space->line_len / 4 + x] =
				data->textures[0].addr[data->ray->texY *
					data->textures[0].line_len /
					4 + data->ray->texY];
	}
	return (0);
}

void    raycasting(t_data *data) 
{
	int	x;

	x = 0;
    while(x < WIDTH)
    {
		init_raycasting(data, x);
		sideDist(data);
		dda(data);
		wall_projection(data);
		draw_tex(data, x);
		x++;
    }
}
