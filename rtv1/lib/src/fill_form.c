/*
** img_fill_inside.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 15:04:42 2014
** Last update Sun Mar 15 16:14:45 2015 Cano Chloe
*/

#include <graph.h>

void		img_fill_inside(t_mlx *mlx, t_img *img, t_point coord[1],
				unsigned long colors[2])
{
  int		test;

  mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
  usleep(10000);
  img_put_pixel(mlx, img, coord, colors[0]);
  ++coord->x;
  if (coord->x < img->size.x && img_get_color(img, coord) != colors[1])
    img_fill_inside(mlx, img, coord, colors);
  coord->x -= 2;
  if (coord->x >= 0 && img_get_color(img, coord) != colors[1])
    img_fill_inside(mlx, img, coord, colors);
  ++coord->x;
  ++coord->y;
  if (coord->y < img->size.y && img_get_color(img, coord) != colors[1])
    img_fill_inside(mlx, img, coord, colors);
  coord->y -= 2;
  if (coord->y >= 0 && img_get_color(img, coord) != colors[1])
    img_fill_inside(mlx, img, coord, colors);
}
