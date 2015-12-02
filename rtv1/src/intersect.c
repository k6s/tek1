/*
** intersect.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:33:36 2015
** Last update Sun Mar 15 16:07:28 2015 Cano Chloe
*/
#include <rtv1.h>

static void	real_position(t_3dpoint *tmp_eye, t_3dpoint *pvec, t_eye *eye,
			      t_obj *obj)
{
  tmp_eye->x = eye->pos.x;
  tmp_eye->y = eye->pos.y;
  tmp_eye->z = eye->pos.z;
  vec3d_inv_rot(pvec, &eye->rot);
  vec3d_inv_rot(tmp_eye, &eye->rot);
  tmp_eye->x -= obj->pos.x;
  tmp_eye->y -= obj->pos.y;
  tmp_eye->z -= obj->pos.z;
  vec3d_inv_rot(pvec, &obj->rot);
  vec3d_inv_rot(tmp_eye, &obj->rot);
}

float		get_inter(t_eye *eye, t_3dpoint *vec, t_obj *obj)
{
  t_3dpoint	tmp_eye;
  t_3dpoint	pvec;

  pvec.x = vec->x;
  pvec.y = vec->y;
  pvec.z = vec->z;
  real_position(&tmp_eye, &pvec, eye, obj);
  if (obj->type == O_SPHERE)
    return (inter_sphere(&tmp_eye, &pvec, obj->obj.sphere.radius));
  if (obj->type == O_PLANE)
    return (inter_plane(&tmp_eye, &pvec));
  if (obj->type == O_CONE)
    return (inter_cone(obj, &tmp_eye, &pvec));
  if (obj->type == O_CYLINDER)
    return (inter_cylinder(obj, &tmp_eye, &pvec));
  return (0);
}
