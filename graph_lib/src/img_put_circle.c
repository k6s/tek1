/*
** draw_circle.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:10:39 2014
** Last update Tue Oct 28 15:03:40 2014 
*/
#include <graph.h>
#include <math.h>

int		img_put_circle(t_mlx *mlx, t_img *img, t_point coord[2],
			    unsigned long color)
{
  double	a;
  t_point	p;

  a = 0;
  while (a < (2 * M_PI))
    {
      p.x =  coord[0].x + coord[1].x * cos(a);
      p.y = coord[0].y + coord[1].x * sin(a);
      img_put_pixel(mlx, img, &p, color);
      a += (2 * M_PI) / (8 * coord[1].x);
    }
  return (1);
}
