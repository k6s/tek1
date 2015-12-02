/*
** disp_utils.c for fdf in /home/cano_c/rendu/IGRAPH/re
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov 23 22:02:31 2014
** Last update Sun Nov 23 23:18:00 2014 Cano Chloe
*/

#include <fdf.h>

void		set_x_len(t_fdf *s_fdf, char **nb_tab)
{
  char		**p;

  if (!(s_fdf->len[X]))
    {
      p = nb_tab;
      while (*p)
	++p;
      s_fdf->len[X] = p - nb_tab;
    }
}

void		get_ratio(t_img *img, size_t *ratio, size_t co, size_t li)
{
  int		x;
  int		y;

  x = (img->size.x  - 50) / co;
  y = (img->size.y  - 50) / li;
  *ratio = x < y ? x : y;
}

void		get_min(t_fdf *s_fdf, t_point *min_max)
{
  size_t	pos_x;
  size_t	pos_y;

  pos_y = 0;
  min_max[0].x = INT_MAX;
  min_max[0].y = INT_MAX;
  min_max[1].x = INT_MIN;
  min_max[1].y = INT_MIN;
  while (pos_y < s_fdf->len[Y] - 1)
    {
      pos_x = 0;
      while (pos_x < s_fdf->len[X])
	{
	  if (s_fdf->map[pos_y][pos_x].x < min_max[0].x)
	    min_max[0].x = s_fdf->map[pos_y][pos_x].x;
	  if (s_fdf->map[pos_y][pos_x].y < min_max[0].y)
	    min_max[0].y = s_fdf->map[pos_y][pos_x].y;
	  if (s_fdf->map[pos_y][pos_x].x > min_max[1].x)
	    min_max[1].x = s_fdf->map[pos_y][pos_x].x;
	  if (s_fdf->map[pos_y][pos_x].y > min_max[1].y)
	    min_max[1].y = s_fdf->map[pos_y][pos_x].y;
	  ++pos_x;
	}
      ++pos_y;
    }
}

void		make_line(t_point *line, t_point *p1, t_point *p2, t_point *offset)
{
  line[0].x = offset->x + p1->x;
  line[0].y = p1->y + offset->y;
  line[1].x = offset->x + p2->x;
  line[1].y = p2->y + offset->y;
}

void		get_offset(t_fdf *s_fdf, t_point *offset, t_mlx *mlx)
{

  t_point	min_max[2];

  get_min(s_fdf, min_max);
  offset->x = 0;
  offset->y = 0;
  if (min_max[0].x < 0)
    offset->x += min_max[0].x * -1;
  if (min_max[0].y < 0)
    offset->y += min_max[0].y * -1;
  offset->x = (mlx->win_size.x -
	       (min_max[1].x - min_max[0].x - offset->x)) / 2;
  offset->y = (mlx->win_size.y
	       - (min_max[1].y - min_max[0].y - offset->y)) / 2;
  if (offset->x < 0)
    offset->x *= -1;
  if (offset->y < 0)
    offset->y *= -1;
}
