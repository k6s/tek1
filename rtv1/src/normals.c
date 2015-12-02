/*
** normals.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Mar 15 14:36:20 2015
** Last update Sun Mar 15 16:10:28 2015 Cano Chloe
*/
#include <rtv1.h>

void		normal_sphere(t_obj *obj, t_3dpoint *i, t_3dpoint *normal)
{
  normal->x = i->x - obj->pos.x;
  normal->y = i->y - obj->pos.y;
  normal->z = i->z - obj->pos.z;
}

void		normal_plane(t_obj *obj, t_3dpoint UN *i, t_3dpoint *normal)
{
  normal->x = 0;
  normal->y = 1;
  normal->z = 0;
  rotate_x(normal, 1 * obj->rot.x);
  rotate_y(normal, 1 * obj->rot.y);
  rotate_z(normal, 1 * obj->rot.z);
}

void		normal_cone(t_obj *obj, t_3dpoint *i, t_3dpoint *normal)
{
  normal->x = 2 * i->x - obj->pos.x;
  normal->z = 2 * i->z - obj->pos.z;
  normal->y = 200;
  rotate_x(normal, 1 * obj->rot.x);
  rotate_x(normal, 1 * obj->rot.y);
  rotate_x(normal, 1 * obj->rot.z);
}

void		normal_cylinder(t_obj *obj, t_3dpoint *i, t_3dpoint *normal)
{
  normal->x = i->x;
  normal->y = i->y;
  normal->z = 0;
  rotate_x(normal, 0 - obj->rot.x);
  rotate_y(normal, 0 - obj->rot.y);
  rotate_z(normal, 0 - obj->rot.z);
  normal->x -= obj->pos.x;
  normal->y -= obj->pos.y;
  normal->z -= obj->pos.z;
}

void		get_normal(t_obj *obj, t_3dpoint *i, t_3dpoint *normal)
{
  if (obj->type == O_SPHERE)
    normal_sphere(obj, i, normal);
  else if (obj->type == O_PLANE)
    normal_plane(obj, i, normal);
  else if (obj->type == O_CONE)
    normal_cone(obj, i, normal);
  else if (obj->type == O_CYLINDER)
    normal_cylinder(obj, i, normal);
}
