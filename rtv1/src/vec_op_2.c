/*
** vec_op_2.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Mar 13 15:46:32 2015
** Last update Sun Mar 15 16:12:16 2015 Cano Chloe
*/
#include <rtv1.h>

void		vec3d_rot(t_3dpoint *v, t_3dpoint *rot)
{
  rotate_x(v, rot->x);
  rotate_y(v, rot->y);
  rotate_z(v, rot->z);
}

void		vec3d_inv_rot(t_3dpoint *v, t_3dpoint *rot)
{
  rotate_x(v, rot->x * -1.00);
  rotate_y(v, rot->y * -1.00);
  rotate_z(v, rot->z * -1.00);
}

void		vec3d_add(t_3dpoint *dst, t_3dpoint *v, t_3dpoint *v2)
{
  dst->x = v->x + v2->x;
  dst->y = v->y + v2->y;
  dst->z = v->z + v2->z;
}

void		vec3d_sub(t_3dpoint *dst, t_3dpoint *v, t_3dpoint *v2)
{
  dst->x = v->x - v2->x;
  dst->y = v->y - v2->y;
  dst->z = v->z - v2->z;
}
