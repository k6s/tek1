/*
** draw_line.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Oct 27 22:23:31 2014
** Last update Fri Nov 21 15:01:05 2014 
*/
#include <graph.h>

static void	switch_point(t_point *from, t_point *to)
{
  int		ptmp;

  ptmp = from->x;
  from->x = to->x;
  to->x = ptmp;
  ptmp = from->y;
  from->y = to->y;
  to->y = ptmp;
}

static void	switch_coord(t_point *point)
{
  int		tmp;

  tmp = point->x;
  point->x = point->y;
  point->y = tmp;
}

static void	init(t_point coord[2], t_point *from, t_point *to, char *inv)
{
  *inv = 0;
  from->x = coord[0].x;
  from->y = coord[0].y;
  to->x = coord[1].x;
  to->y = coord[1].y;
  if ((to->x - from->x) < ABS(to->y - from->y))
    {
      if (from->y > to->y)
	switch_point(from, to);
      switch_coord(from);
      switch_coord(to);
      *inv = 1;
    }
  else if (from->x > to->x)
    switch_point(from, to);
}

int		img_put_line(t_mlx *mlx, t_img *img, t_point coord[2],
			     unsigned long color)
{
  char		inv;
  t_point	from;
  t_point	to;
  t_point	pix;

  init(coord, &from, &to, &inv);
  pix.x = from.x - 1;
  while (++pix.x <= to.x)
    {
      if (to.x - from.x)
	{
	  pix.y = from.y + ((to.y - from.y) * (pix.x - from.x )) / (to.x - from.x);
	  if (inv)
	    switch_coord(&pix);
	  img_put_pixel(mlx, img, &pix, color);
	  if (inv)
	    switch_coord(&pix);
	}
    }
  return (1);
}
