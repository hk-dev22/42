/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:11:03 by hkortbi           #+#    #+#             */
/*   Updated: 2021/10/01 19:15:39 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
#define BLACK_PIXEL 0x000000
# define WIDTH 720
# define HEIGHT 480

typedef struct s_vmap
{
    int collectible;
    int exit;
    int starting_position;
    int columns;
    int rows;
    int error;
}           t_vmap;

/* Variables necessaires pour le rapport de proportionnalite */
typedef struct s_draw
{
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
}				t_draw;

typedef struct s_player
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
}               t_player;

typedef struct s_ray
{
    	double cameraX;
		double rayDirX;
		double rayDirY;
		int mapX;
		int mapY;
        ///Longueur des rayons de la position actuelle au prochain x ou y
        double sideDistX; ///Distance entre le joueur et 1e prochain mur vertical
		double sideDistY; ///Distance entre le joueur et 1e prochain mur horizontal
		double deltaDistX;///Distance entre deux murs verticaux
		double deltaDistY;///Distance entre deux murs horizontaux
		int stepX; ///si gauche x=-1, si droite x=+1
		int stepY; ///si avance y=+1 et si recule y=-1
        int sideHV; ///est-ce un mur horizontal ou vertical?
        double perpWallDist;
        int lineHeight;
        int drawStart;
	    int drawEnd;
        double wallX;
        int texX;
        int texY;
        int texStep;
}               t_ray;


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; //bits per pixel
	int		line_len;
	int		endian;
	int 	width;
	int 	height;

}	t_img;

typedef struct    s_data
{
	void	*mlx_ptr;
    void	*mlx_win;
    t_ray   *ray;
	t_img	*img_space;
	t_img	textures[1];
	t_player	*player;
    char    **map2d;
    t_vmap	*vmap;

}                 t_data;

t_data *init_data();
void    first_read(t_data *data, char *file);
int			get_next_line(int fd, char **line);
int    get_map2d(t_data *data, char *file);
void exit_all(t_data *data);
int	handle_close(t_data *data);
void	load_image(t_data *data, t_img *img, char *path);
void    draw_minimap(t_data *data);
void    init_game(t_data *data);
void    draw_miniplayer(t_data *data);
void    raycasting(t_data *data);
int draw_vline(t_img *img, int x, int drawStart, int drawEnd, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
t_ray   *init_ray(void);
t_player *init_player(void);
t_vmap *init_vmap(void);
t_img    *init_img(void);
void    move_player(t_data *data, int keysym);
int draw_vline2(t_data *data, int x, int drawStart, int drawEnd, int color);
void	clear_background(t_img *img);
int	    get_pixel(t_img *img, int x, int y);
void	set_pixel(t_img *img, int x, int y, int color);
void	get_texture(t_data *data);

#endif