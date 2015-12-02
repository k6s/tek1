/*
** scene_cross.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Mar 15 14:41:33 2015
** Last update Sun Mar 15 16:11:19 2015 Cano Chloe
*/
#include <rtv1.h>

t_obj		*make_cross_bar(t_scene *s_scene)
{
  t_obj		*new;

  if (!(new = add_obj(&s_scene->objs, O_CYLINDER)))
    return (NULL);
  my_bzero(new, sizeof(*new));
  new->type = O_CYLINDER;
  new->obj.cylinder.r = 0.3;
  new->obj.cylinder.min = 0;
  new->obj.cylinder.max = 13;
  return (new);
}

int		make_cross(t_scene *s_scene)
{
  t_obj		*bar;

  if (!(bar = make_cross_bar(s_scene)))
    return (-1);
  bar->color = 0xff000000;
  bar->rot.z = 1.5707;
  if (!(bar = make_cross_bar(s_scene)))
    return (-1);
  bar->color = 0x0000ff00;
  bar->rot.x = -1.5707;
  bar->pos.x = 0;
  if (!(bar = make_cross_bar(s_scene)))
    return (-1);
  bar->color = 0x00ff0000;
  return (0);
}
