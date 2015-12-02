/*
** mtx_op.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:44:34 2015
** Last update Sun Mar 15 16:07:55 2015 Cano Chloe
*/
#include <rtv1.h>

void		mult_mtx(float mtx[3][3], t_3dpoint *point)
{
  t_3dpoint	tmp;

  tmp.x = point->x;
  tmp.y = point->y;
  point->x = point->x * mtx[0][0] + point->y * mtx[0][1] + point->z
    * mtx[0][2];
  point->y = tmp.x * mtx[1][0] + point->y * mtx[1][1] + point->z * mtx[1][2];
  point->z = tmp.x * mtx[2][0] + tmp.y * mtx[2][1] + point->z * mtx[2][2];
}
