/*
** events.c for fdf in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov 23 22:57:36 2014
** Last update Sun Nov 23 23:15:35 2014 Cano Chloe
*/

#include <fdf.h>

int		handle_key(int keycode, void *param)
{
  if (keycode == K_ESC)
    {
      free_map(((t_fdf *)param)->map);
      exit(0);
    }
  return (0);
}

int		handle_expose(void *param)
{
  mlx_put_image_to_window(((t_expose *)param)->mlx->mlx,
			  ((t_expose *)param)->mlx->win,
			  ((t_expose *)param)->img->img, 0, 0);
  return (0);
}
