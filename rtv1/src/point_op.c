/*
** point_op.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Mar 15 14:39:42 2015
** Last update Sun Mar 15 16:10:38 2015 Cano Chloe
*/
#include <rtv1.h>

void		set_3dpoint(t_3dpoint *p, float x, float y, float z)
{
  p->x = x;
  p->z = z;
  p->y = y;
}
