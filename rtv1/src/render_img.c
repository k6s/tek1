/*
** render_img.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:50:04 2015
** Last update Sun Mar 15 16:10:54 2015 Cano Chloe
*/
#include <rtv1.h>
#include <float.h>

t_obj		*get_closest_obj(t_scene *s_scene, t_3dpoint *vec,
				 float *min_dist)
{
  float		new_dist;
  t_obj		*closest;
  t_obj		*current;

  closest = NULL;
  current = s_scene->objs;
  *min_dist = FLT_MAX;
  while (current)
    {
      if ((new_dist = get_inter(&s_scene->eye, vec, current)))
	{
	  if (new_dist < *min_dist)
	    {
	      *min_dist = new_dist;
	      closest = current;
	    }
	}
      current = current->next;
    }
  return (closest);
}

long		get_point_color(t_scene *s_scene, t_3dpoint *vec)
{
  float		min_dist;
  t_obj		*closest;
  t_3dpoint	k;
  long		color;

  color = 0x000000ff;
  if ((closest = get_closest_obj(s_scene, vec, &min_dist)))
    {
      k.x = s_scene->eye.pos.x + min_dist * vec->x;
      k.y = s_scene->eye.pos.y + min_dist * vec->y;
      k.z = s_scene->eye.pos.z + min_dist * vec->z;
      color = add_light(s_scene, &k, closest);
    }
  else
    color = 0;
  return (color);
}

void		render_img(t_mlx *s_mlx, t_img *s_img, t_scene *s_scene)
{
  t_point	pos;
  t_3dpoint	vec;
  long		pix_color;

  vec.z = DIST_SCREEN;
  pos.y = 0;
  while (pos.y < s_img->size.y)
    {
      pos.x = 0;
      while (pos.x < s_img->size.x)
	{
	  vec.x = s_img->size.x / 2 - pos.x;
	  vec.y = s_img->size.y / 2 - pos.y;
	  pix_color = get_point_color(s_scene, &vec);
	  img_put_pixel(s_mlx, s_img, &pos, pix_color);
	  ++pos.x;
	}
      ++pos.y;
    }
}
