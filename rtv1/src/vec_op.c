/*
** vec_op.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:54:01 2015
** Last update Sun Mar 15 16:12:02 2015 Cano Chloe
*/
#include <rtv1.h>

float		vec_norme(t_3dpoint *point)
{
  return (sqrt(pow(point->x, 2) + pow(point->y, 2) + pow(point->z, 2)));
}

t_3dpoint	*vec_dup(t_3dpoint *dest, t_3dpoint *src)
{
  dest->x = src->x;
  dest->y = src->y;
  dest->z = src->z;
  return (dest);
}

t_3dpoint	*vec_scalar_div(t_3dpoint *v, float f)
{
  v->x /= f;
  v->y /= f;
  v->z /= f;
  return (v);
}

float		vec_dot_product(t_3dpoint *v1, t_3dpoint *v2)
{
  return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

float		vec_angle(t_3dpoint *v1, t_3dpoint *v2)
{
  float		n1;
  float		n2;
  t_3dpoint	c1;
  t_3dpoint	c2;

  vec_dup(&c1, v1);
  vec_dup(&c2, v2);
  n1 = vec_norme(&c1);
  n2 = vec_norme(&c2);
  vec_scalar_div(&c1, n1);
  vec_scalar_div(&c2, n2);
  return (vec_dot_product(&c1, &c2));
}
