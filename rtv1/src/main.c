/*
** main.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb  9 13:01:08 2015
** Last update Sun Mar 15 16:57:05 2015 Cano Chloe
*/
#include <rtv1.h>

void		my_bzero(void *mem, size_t len)
{
  while (len-- > 0)
    *((char *)mem + len) = 0;
}

void		free_scene(t_scene *s_scene)
{
  t_obj		*objs;
  t_obj		*tmp;

  objs = s_scene->objs;
  while (objs)
    {
      tmp = objs;
      objs = objs->next;
      free(tmp);
    }
}

int		expose_handle(t_expose *e)
{
  if (!(mlx_put_image_to_window(e->mlx->mlx, e->mlx->win,
				e->img->img, 0, 0)))
    return (0);
  return (1);
}

int		key_handle(int keycode, void *param)
{
  t_expose	*e;

  e = param;
  if (keycode == K_ESC)
    {
      mlx_destroy_window(e->mlx->mlx, e->mlx->win);
      free_scene(e->free);
      exit(0);
    }
  return (0);
}

int		main(void)
{
  t_mlx		s_mlx;
  t_img		s_img;
  t_scene	s_scene;
  t_expose	s_expose;

  if (!(s_mlx.mlx = mlx_init()))
    return (-1);
  if (!(s_mlx.win = mlx_new_window(s_mlx.mlx, 800, 600, "rtv1")))
    return (-1);
  s_img.size.x = 800;
  s_img.size.y = 600;
  if (!(new_img(&s_mlx, &s_img)))
    return (-1);
  if (make_scene(&s_scene))
    return (-1);
  s_expose.mlx = &s_mlx;
  s_expose.free = &s_scene;
  render_img(&s_mlx, &s_img, &s_scene);
  s_expose.img = &s_img;
  if (!(mlx_put_image_to_window(s_mlx.mlx, s_mlx.win, s_img.img, 0, 0)))
    return (-1);
  mlx_expose_hook(s_mlx.win, &expose_handle, &s_expose);
  mlx_key_hook(s_mlx.win, &key_handle, &s_expose);
  mlx_loop(s_mlx.mlx);
  return (0);
}
