/*
** img_get_color.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 15:09:00 2014
** Last update Wed Oct 29 17:36:10 2014 
*/

#include <graph.h>

unsigned long	img_get_color(t_img *img, t_point *pix)
{
  unsigned long	color;

  color = 0;
  color |= *(unsigned char *)
    (img->data + pix->y * img->size_line + pix->x * img->bpp / 8 ) << 24;
  color |= *(unsigned char *)
    (img->data + pix->y * img->size_line + pix->x * img->bpp / 8 + 1) << 16;
  color |= *(unsigned char *)
    (img->data + pix->y * img->size_line + pix->x * img->bpp / 8 + 2) << 8;
  color |= *(unsigned char *)
    (img->data + pix->y * img->size_line + pix->x * img->bpp / 8 + 3);
  return (color);
}
