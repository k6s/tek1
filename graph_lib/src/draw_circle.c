/*
** draw_circle.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:10:39 2014
** Last update Tue Oct 28 12:38:28 2014 
*/
#include <graph.h>
#include <math.h>

int		draw_circle(t_mlx *mlx, t_point *orig, int r, int color)
{
  double	a;

  a = 0;
  while (a < (2 * M_PI))
    {
      if (!(mlx_pixel_put(mlx->mlx, mlx->win,
			  orig->x + r * cos(a), orig->y + r * sin(a), color)))
	return (0);
      a += (2 * M_PI) / (8 * r);
    }
  return (1);
}
