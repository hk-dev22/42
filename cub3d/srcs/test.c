/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:24:13 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/30 14:09:44 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "math.h"
#include "time.h"

# define M 64
# define m 16
# define BUFFER_SIZE 1
# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define BLACK 0xFF000000
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define BLUE_PIXEL 0x0000FF
#define YELLOW_PIXEL 0xFFFF00
# define WIDTH 1280
# define HEIGHT 720

#define MLX_ERROR 1

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_player
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
}               t_player;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
    t_player *player;
}	t_data;

t_player *init_player()
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

t_img *init_img()
{
    t_img *img;

    img = (t_img *)malloc(sizeof(t_img));
    img->mlx_img = NULL;
    img->addr = NULL;
    img->bpp = 0;
    img->endian = 0;
    img->line_len = 0;
    return (img);
}

t_data *init_data()
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->img = init_img();
    data->player = init_player();
    if (!data || !data->img || !data->player)
        ft_putstr_fd("Error: memory allocation!\n", 1);
    return (data);
}
double start, end;///Temps de la sequence courante

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

int render_line(t_img *img, int x, int drawStart, int drawEnd, int color)
{
    int i;

    i = drawStart;
    while (i < drawEnd)
        img_pix_put(img, x, i++, color);
    return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < screenHeight)
	{
		j = 0;
		while (j < screenWidth)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
    double frameTime = (end - start) / CLOCKS_PER_SEC;
    double moveSpeed = frameTime * 100.0; ///la constante est en squares/second
    double rotSpeed = frameTime * 50.0; ///la constante est en in radians/second
    printf("frametime: %f\n", frameTime);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
		
	if (keysym == XK_w)
    {
        if(worldMap[(int)(data->player->posX + data->player->dirX * moveSpeed)][(int)(data->player->posY)] == 0) data->player->posX += data->player->dirX * moveSpeed ;
        if(worldMap[(int)(data->player->posX)][(int)(data->player->posY + data->player->dirY * moveSpeed)] == 0) data->player->posY += data->player->dirY * moveSpeed ;
    }
    if (keysym == XK_s)
    {
        if(worldMap[(int)(data->player->posX - data->player->dirX * moveSpeed)][(int)(data->player->posY)] == 0) data->player->posX -= data->player->dirX * moveSpeed;
        if(worldMap[(int)(data->player->posX)][(int)(data->player->posY - data->player->dirY * moveSpeed)] == 0) data->player->posY -= data->player->dirY * moveSpeed;
    }
    if (keysym == XK_a)
    { 
       ///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
      double oldDirX = data->player->dirX;
      data->player->dirX = data->player->dirX * cos(rotSpeed) - data->player->dirY * sin(rotSpeed);
      data->player->dirY = oldDirX * sin(rotSpeed) + data->player->dirY * cos(rotSpeed);
      double oldPlaneX = data->player->planeX;
      data->player->planeX = data->player->planeX * cos(rotSpeed) - data->player->planeY * sin(rotSpeed);
      data->player->planeY = oldPlaneX * sin(rotSpeed) + data->player->planeY * cos(rotSpeed);
    }
    if (keysym == XK_d)
    {
        ///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
      double oldDirX = data->player->dirX;
      data->player->dirX = data->player->dirX * cos(-rotSpeed) - data->player->dirY * sin(-rotSpeed);
      data->player->dirY = oldDirX * sin(-rotSpeed) + data->player->dirY * cos(-rotSpeed);
      double oldPlaneX = data->player->planeX;
      data->player->planeX = data->player->planeX * cos(-rotSpeed) - data->player->planeY * sin(-rotSpeed);
      data->player->planeY = oldPlaneX * sin(-rotSpeed) + data->player->planeY * cos(-rotSpeed);
    }
		
		
	return (0);
}


void    raycasting(t_data *data)
{
    int w = screenWidth;
    int h = screenHeight;
    start = clock();
    for(int x = 0; x < w; x++)
    {
      ///calcul de la position et de l'orientation du rayon
      double cameraX = 2 * x / (double)(w) - 1; ///Coordonner x dans l'espace de la camera
      double rayPosX = data->player->posX;				 ///  Coordonner x de rayon dans l'espace
      double rayPosY = data->player->posY;                 /// Coordonner y de rayon dans l'espace
      double rayDirX = data->player->dirX + data->player->planeX * cameraX;
      double rayDirY = data->player->dirY + data->player->planeY * cameraX;
      ///Dans quelle case de la carte, nous nous situons au debut
      int mapX = (int)(rayPosX);
      int mapY = (int)(rayPosY);

      //printf("camx: %f, rayPx: %f, rayPy: %f, rayDx: %f, rayDy: %f, mapX: %d, mapY: %d\n", cameraX, rayPosX, rayPosY, rayDirX, rayDirY, mapX, mapY);
 
      ///Longueur des rayons de la position actuelle au prochain x ou y
      double distMurX; ///Distance entre le joueur et 1e prochain mur vertical
      double distMurY; ///Distance entre le joueur et 1e prochain mur horizontal
 
       ///Longueur des rayons de la position  du x ou y actuel au prochain x ou y
      double dist2MurX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)); ///Distance entre deux murs verticaux
      double dist2MurY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY)); ///Distance entre deux murs horizontaux
      double longueurMur;

       ///Etape du prochain mouvement
      int etapeX; ///si gauche x=-1, si droite x=+1
      int etapeY; ///si avance y=+1 et si recule y=-1
 
      int touche = 0; ///Y a-t-il un mur de detecter?
      int murVertiOuHori; ///est-ce un mur horizontal ou vertical?
      printf("rayPosX: %f, mapX: %d\n", rayPosX, mapX);
 
      ///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur vertical le plus proche en fonction de la prochaine etape x
      if (rayDirX < 0) /// Si le rayon est oriente vers la gauche
      {
        etapeX = -1;
        distMurX = (rayPosX - mapX) * dist2MurX; ///  On calcule la distance entre joueur et 1e prochain mur vertical
      }
      else ///Si le rayon est oriente vers la droite
      {
        etapeX = 1;
        distMurX = (mapX + 1.0 - rayPosX) * dist2MurX; /// On calcule la distance entre joueur et 1e prochain mur vertical
      }
      ///Calcul le sens de la prochaine etape et la distance entre le joueur et le mur horizontal le plus proche en fonction de la prochaine etape y
      if (rayDirY < 0)
      {
        etapeY = -1;///  On recule
        distMurY = (rayPosY - mapY) * dist2MurY;///  On calcule la distance entre le joueur et 1e prochain mur horizontal
      }
      else
      {
        etapeY = 1;///  On avance
        distMurY = (mapY + 1.0 - rayPosY) * dist2MurY;/// On calcule la distance entre joueur et 1e prochain mur horizontal
      }
      ///lance de DDA = Digital Differential Analysis (algorithme de detection des murs)
      while (touche == 0)
      {
        ///Saute au prochain carre de la map soit vers la  direction x, soit vers la direction y en fonction du mur le plus proche
        if (distMurX < distMurY)
        {
          distMurX += dist2MurX;
          mapX += etapeX;
          murVertiOuHori = 0; ///Mur vertical
        }
        else
        {
          distMurY += dist2MurY;
          mapY += etapeY;
          murVertiOuHori = 1; ///Mur vertical
        }
        ///Verifier si le rayon a detecte un mur
        if (worldMap[mapX][mapY] > 0) touche = 1;
      }
      longueurMur = 0;
      ///Calcul de la distance projetee sur la direction de la camera (La distance oblique donnera un effet fisheye !)
      if (murVertiOuHori == 0)
        longueurMur = distMurX - dist2MurX;
      else
        longueurMur = distMurY - dist2MurY;
      printf("distMurX: %f, dist2Murx: %f\n", distMurX, dist2MurX);
		  printf("distMurY: %f, dist2Mury: %f\n", distMurY, dist2MurY);
      // printf("longueur mur: %f\n", longueurMur);
      // printf("mapX: %d, rayPosx: %f, rayDirx: %f, etapeX: %d\n", mapX, rayPosX, rayDirX, etapeX);
      //printf("longueur mur: %f\n", longueurMur);
 
      ///Calculer la hauteur de la ligne appelee a l'ecran
      int hauteurMur = abs((int)(h / longueurMur));
 
      ///Calculer le plus bas et le plus eleve des pixels a remplir dans la bande actuelle
      int drawStart = -hauteurMur / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = hauteurMur / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;
      //choose wall color
      int color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RED_PIXEL;    break; //red
        case 2:  color = GREEN_PIXEL;  break; //green
        case 3:  color = BLUE_PIXEL;   break; //blue
        case 4:  color = WHITE_PIXEL;  break; //white
        default: color = YELLOW_PIXEL; break; //yellow
      }

      //printf("Hauteur mur: %d\n", hauteurMur);
      //draw the pixels of the stripe as a vertical line
      render_line(data->img, x, drawStart, drawEnd, color);
    }
    end = clock();
}


int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
    data->img->mlx_img = mlx_new_image(data->mlx_ptr, screenWidth, screenHeight);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
    raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
    mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	return (0);
}

int	main(void)
{
	t_data	*data;

    data = init_data();
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, screenWidth, screenHeight, "Raycasting");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
    data->player->posX = 22;
    data->player->posY = 12;  //x and y start position
    data->player->dirX = -1, data->player->dirY = 0; //initial direction vector
    data->player->planeX = 0, data->player->planeY = 0.66; //the 2d raycaster version of camera plane

	/* Setup hooks */ 
	// data->img->mlx_img = mlx_new_image(data->mlx_ptr, screenWidth, screenHeight);
	// data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
	// 		&data->img->line_len, &data->img->endian);

	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}