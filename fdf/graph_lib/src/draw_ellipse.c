/*
** draw_ellipse.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:10:39 2014
** Last update Tue Oct 28 12:49:09 2014 
*/
#include <graph.h>
#include <math.h>

int		draw_ellipse(t_mlx *mlx, t_point *orig, int r[2], int color)
{
  double	a;

  a = 0;
  while (a < (2 * M_PI))
    {
      if (!(mlx_pixel_put(mlx->mlx, mlx->win,
			  orig->x + r[0] * cos(a), orig->y + r[1] * sin(a),
			  color)))
	return (0);
      a += (2 * M_PI) / (((8 * r[0]) + (8 * r[1])) / 2);
    }
  return (1);
}
