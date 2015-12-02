/*
** make_scene.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:44:07 2015
** Last update Sun Mar 15 16:06:32 2015 Cano Chloe
*/
#include <rtv1.h>

t_obj		*add_obj(t_obj **objs, int type)
{
  t_obj		*new;
  t_obj		*current;

  if (!(new = malloc(sizeof(*new))))
    return (NULL);
  new->type = type;
  if (new)
    {
      new->next = NULL;
      current = *objs;
      if (!current)
	*objs = new;
      else
	{
	  while (current->next)
	    current = current->next;
	  current->next = new;
	}
    }
  return (new);
}

int		make_scene_objs(t_scene *s_scene)
{
  t_obj		*new;

  if (!(new = add_obj(&s_scene->objs, O_SPHERE)))
    return (-1);
  new->obj.sphere.radius = 40;
  set_3dpoint(&new->pos, 40.00, 80.0, 0.0);
  set_3dpoint(&new->rot, 0.0, 0.0, 0.0);
  new->color = 0x00006600;
  new->brillance = 0.0;
  if (!(new = add_obj(&s_scene->objs, O_SPHERE)))
    return (-1);
  new->obj.sphere.radius = 10;
  set_3dpoint(&new->pos, -30.00, 00.0, 20.0);
  set_3dpoint(&new->rot, 0.0, 0.0, 0.0);
  new->color = 0xffffff00;
  new->brillance = 0.3;
  if (!(new = add_obj(&s_scene->objs, O_CONE)))
    return (-1);
  set_3dpoint(&new->pos, 80, 40, -50);
  set_3dpoint(&new->rot, 0, 0, 0);
  new->obj.cone.min = -100;
  new->obj.cone.max = 0;
  new->color = 0x00660000;
  new->brillance = 0.0;
  return (0);
}

int		make_scene_plane(t_scene *s_scene)
{
  t_obj		*new;

  if (!(new = add_obj(&s_scene->objs, O_PLANE)))
    return (-1);
  set_3dpoint(&new->pos, 0, 0, 0);
  set_3dpoint(&new->rot, 0, 0, 0);
  new->color = 0xffffff00;
  new->brillance = 0;
  return (0);
}

int		make_scene(t_scene *s_scene)
{
  s_scene->objs = NULL;
  if (make_scene_objs(s_scene))
    return (-1);
  if (make_cross(s_scene))
    return (-1);
  if (make_scene_plane(s_scene))
    return (-1);
  set_3dpoint(&s_scene->eye.pos, 0, 20, -500);
  set_3dpoint(&s_scene->eye.rot, -0.3, 0.23, 0.0);
  set_3dpoint(&s_scene->spot, -40, 40, -100);
  s_scene->spot_color = 0x0000ffff;
  return (0);
}
