/*
** proj_para.c for graph lib in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf/graph_lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Nov 19 18:18:18 2014
** Last update Sun Nov 23 23:20:20 2014 Cano Chloe
*/

#include <graph.h>

# define CTE 1

# define CTE1	0.707
# define CTE3	-1
# define CTE2	0.707

void		proj_para(t_3dpoint *point3d, t_point *point)
{
  point->x = ((double)point3d->x + (double)CTE * (double)point3d->z);
  point->y = ((double)point3d->y + (double)((double)CTE / (double)2)
	      * (double)point3d->z);
}

void		proj_iso(t_3dpoint *point3d, t_point *point, int ratio)
{
  point->x = (double)CTE1 * (double)point3d->x * 20 - CTE2 * (double)point3d->y
    * ratio;
  point->y = (double)point3d->z * -2 + point3d->x * CTE1 / 2 * 20 + point3d->y
    * CTE2 / 2 * ratio;
}
