/*
** img_put_pixel.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:55:02 2014
** Last update Tue Oct 28 17:35:05 2014 
*/

#include <graph.h>

void		img_put_pixel(t_mlx *mlx, t_img *img, t_point *pix,
			      unsigned long color)
{
  color = mlx_get_color_value(mlx->mlx, color);
  *(char *)(img->data + pix->y * img->size_line + pix->x * img->bpp / 8) =
    (color & 0xFF000000) >> 24;
  *(char *)(img->data + pix->y * img->size_line + pix->x * img->bpp / 8 + 1) =
    (color & 0xFF0000) >> 16;
  *(char *)(img->data + pix->y * img->size_line + pix->x * img->bpp / 8 + 2) =
    (color & 0xFF00) >> 8;
  *(char *)(img->data + pix->y * img->size_line + pix->x * img->bpp / 8 + 3) =
    (color & 0xFF);
}
