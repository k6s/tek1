/*
** img_fill_inside.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 15:04:42 2014
** Last update Sun Mar 15 16:14:54 2015 Cano Chloe
*/

#include <graph.h>

void		img_fill_inside(t_mlx *mlx, t_img *img, t_point *coord,
				unsigned long colors[2])
{
  unsigned int	color;

  img_put_pixel(mlx, img, coord, colors[0]);
  ++coord->x;
  color = img_get_color(img, coord);
  if (coord->x <= img->size.x && color != colors[1] && color != colors[0])
    img_fill_inside(mlx, img, coord, colors);
  coord->x -= 2;
  color = img_get_color(img, coord);
  if (coord->x >= 0 && color != colors[1] && color != colors[0])
    img_fill_inside(mlx, img, coord, colors);
  ++coord->x;
  ++coord->y;
  color = img_get_color(img, coord);
  if (coord->y <= img->size.y && color != colors[1] && color != colors[0])
    img_fill_inside(mlx, img, coord, colors);
  coord->y -= 2;
  color = img_get_color(img, coord);
  if (coord->y >= 0 && color != colors[1] && color != colors[0])
    img_fill_inside(mlx, img, coord, colors);
  ++coord->y;
}
