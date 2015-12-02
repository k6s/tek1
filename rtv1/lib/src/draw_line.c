/*
** draw_line.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Oct 27 22:23:31 2014
** Last update Sun Mar 15 16:14:34 2015 Cano Chloe
*/
#include <graph.h>

static void	init(t_point *pfrom, t_point *pto, t_point *from, t_point *to)
{
  t_point	*tmp;
  int		ptmp;

  from->x = pfrom->x;
  from->y = pfrom->y;
  to->x = pto->x;
  to->y = pto->y;
  if ((to->x - from->x) < ABS(to->y - from->y))
    {
      ptmp = from->x;
      from->x = from->y;
      from->y = ptmp;
      ptmp = to->x;
      to->x = to->y;
      to->y = ptmp;
    }
  else if (from->x > to->x)
    {
      tmp = to;
      to = from;
      from = tmp;
    }
}

int		draw_line(t_mlx *mlx, t_point *pfrom, t_point *pto, int color)
{
  int		x;
  t_point	from;
  t_point	to;

  init(pfrom, pto, &from, &to);
  x = from.x - 1;
  while (++x <= to.x)
    {
      if (!(mlx_pixel_put(mlx->mlx, mlx->win, x, from.y
			 + ((to.y - from.y) * (x - from.x))
			  / (to.x - from.x), color)))
	return (0);
    }
  return (1);
}
