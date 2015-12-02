/*
** light.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:38:43 2015
** Last update Sun Mar 15 16:38:21 2015 Cano Chloe
*/
#include <rtv1.h>

static long	color_brillance(long color, int brillance, long spotc)
{
  long		color_tmp;

  color_tmp = 0x0000ff00 & (long)((1 - brillance) * (color & 0x0000ff00));
  color_tmp |= 0x00ff0000 & (long)((1 - brillance) * (color & 0x00ff0000));
  color_tmp |= 0xff000000 & (long)((1 - brillance) * (color & 0xff000000));
  color = 0x0000ff00 & (long)((spotc * brillance) + (color_tmp & 0x0000ff00));
  color |= 0x00ff0000 & (long)((spotc * brillance) + (color_tmp & 0x00ff0000));
  color |= 0xff000000 & (long)((spotc * brillance) + (color_tmp & 0xff000000));
  return (color);
}

/*
**   if (closest->type == O_CYLINDER)
**      return (closest->color);
*/

long		add_light(t_scene *s_scene, t_3dpoint *k, t_obj *closest)
{
  t_3dpoint	svec;
  t_3dpoint	ivec;
  float		a;
  long		color_tmp;
  long		color;

  my_bzero(&ivec, sizeof(ivec));
  svec.x = s_scene->spot.x - k->x;
  svec.y = s_scene->spot.y - k->y;
  svec.z = s_scene->spot.z - k->z;
  get_normal(closest, k, &ivec);
  a = (a = vec_angle(&svec, &ivec)) < 0 ? 0 : a;
  color = closest->color;
  color_tmp = color_brillance(closest->color, closest->brillance,
			      s_scene->spot_color);
  color = 0x0000ff00 & (long)(a * (color_tmp & 0x0000ff00));
  color |= 0x00ff0000 & (long)(a * (color_tmp & 0x00ff0000));
  color |= 0xff000000 & (long)(a * (color_tmp & 0xff000000));
  return (color | 0x000000ff);
}
