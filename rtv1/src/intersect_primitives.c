/*
** intersect_primitives.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Mar 15 14:32:41 2015
** Last update Sun Mar 15 16:09:25 2015 Cano Chloe
*/
#include <rtv1.h>

float		inter_sphere(t_3dpoint *point, t_3dpoint *vec, float rad)
{
  float		a;
  float		b;
  float		c;

  a = pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2);
  b = 2 * vec->x * point->x + 2 * vec->y * point->y + 2 * point->z * vec->z;
  c = pow(point->x, 2) + pow(point->y, 2) + pow(point->z, 2) - pow(rad, 2);
  return (solve_poly_min(a, b, c));
}

float		inter_plane(t_3dpoint *point, t_3dpoint *vec)
{
  float		inter;

  if (ABS(vec->y) < 0.0001)
    return (0);
  inter = -1.00 * (point->y / vec->y);
  return (inter > 0 ? inter : 0);

}

static float	truncate_cylinder(t_obj *obj, float a, float *s, float *p)
{
  float		min;
  float		max;

  min = obj->obj.cylinder.min;
  max = obj->obj.cylinder.max;
  if (a > 0 && s[0] > 0 && p[0] >= min && p[0] <= max)
    {
      if (s[1] > 0 && p[1] >= min && p[1] <= max)
	return (s[1] < s[0] ? s[1] : s[0]);
      return (s[0]);
    }
  if (a > 0 && s[1] > 0 && p[1] >= min && p[1] <= max)
    return (s[1]);
  return (0);
}

float		inter_cone(t_obj *obj, t_3dpoint *point, t_3dpoint *vec)
{
  float		a;
  float		b;
  float		c;
  float		s[2];
  float		p[2];

  a = pow(vec->x, 2) + pow(vec->z, 2) - pow(vec->y, 2);
  b = 2 * vec->x * point->x + 2 * vec->z * point->z - 2 * vec->y * point->y;
  c = pow(point->x, 2) + pow(point->z, 2) - pow(point->y, 2);
  a = solve_poly(s, a, b, c);
  p[0] = vec->y * s[0] + point->y;
  p[1] = vec->y * s[1] + point->y;
  b = obj->obj.cone.min;
  c = obj->obj.cone.max;
  if (a > 0 && s[0] > 0 && p[0] >= b && p[0] <= c)
    {
      if (s[1] > 0 && p[1] >= b && p[1] <= c)
	return (s[1] < s[0] ? s[1] : s[0]);
      return (s[0]);
    }
  if (a > 0 && s[1] > 0 && p[1] >= b && p[1] <= c)
    return (s[1]);
  return (0);
}

float		inter_cylinder(t_obj *obj, t_3dpoint *point, t_3dpoint *vec)
{
  float		a;
  float		b;
  float		c;
  float		s[2];
  float		p[2];

  a = pow(vec->x, 2) + pow(vec->z, 2);
  b = 2 * vec->x * point->x + 2 * vec->z * point->z;
  c = pow(point->x, 2) + pow(point->z, 2) - obj->obj.cylinder.r;
  a = solve_poly(s, a, b, c);
  p[0] = vec->y * s[0] + point->y;
  p[1] = vec->y * s[1] + point->y;
  return (truncate_cylinder(obj, a, s, p));
}
