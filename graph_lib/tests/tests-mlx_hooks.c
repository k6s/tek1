/*
** tests-mlx_hooks.c for graph lib in /home/cano_c/rendu/IGRAPH/lib/tests
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Oct 29 17:48:04 2014
** Last update Wed Oct 29 19:26:28 2014 
*/

#include <graph.h>

int		mouse_handle(int button, int x, int y, t_expose *expose)
{
  t_point	pix;

  pix.x = x;
  pix.y = y;
  if (button = M_LB && x >= 0 && x < expose->img->size.x
      && y >= 0 && y <  expose->img->size.y)
      img_put_pixel(expose->mlx->mlx, expose->img->img, &pix, 0xFFFFFFFF);
  mlx_put_image_to_window(expose->mlx->mlx, expose->mlx->win, expose->img->img,
			  0, 0);
}

int		keys_handle(int keycode, t_expose *expose)
{
  if (keycode == K_ESC)
    {
      mlx_destroy_image(expose->mlx->mlx, expose->img->img);
      mlx_destroy_window(expose->mlx->mlx, expose->mlx->win);
      exit(0);
    }
  return (1);
}

int		expose_func(t_expose *expose)
{
  if (!(mlx_put_image_to_window(expose->mlx->mlx, expose->mlx->win,
				expose->img->img, expose->img->pos.x,
				expose->img->pos.y)))
    return (0);
  return (1);
}

void		mlx_hooks(t_mlx *mlx, t_img *img)
{
  t_expose	expose;

  expose.mlx = mlx;
  expose.img = img;
  mlx_expose_hook(mlx->win, &expose_func, &expose);
  mlx_key_hook(mlx->win, &keys_handle, &expose);
  mlx_mouse_hook(mlx->win, &mouse_handle, &expose);
  mlx_loop(mlx->mlx);
}

int		main(void)
{
  t_mlx		mlx;
  t_img		img;
  t_point	pos[2];
  unsigned long	colors[2];

  if (!(mlx.mlx = mlx_init()))
    return (1);
  if (!(mlx.win = mlx_new_window(mlx.mlx, mlx.win_size.x, mlx.win_size.y,
				 "test")))
    return (1);
  img.size.x = 10000;
  img.size.y = 10000;
  if (!(new_img(&mlx, &img)))
    return (1);
  pos[0].x = 300;
  pos[0].y = 300;
  pos[1].x = 100;
  colors[1] = 0xFFFFFFFF;
  colors[0] = 0xFF0000FF;
  //  img_put_circle(&mlx, &img, pos, 0xFFFFFFFF);
  //img_fill_inside(&mlx, &img, &pos[0], colors);
  mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
  mlx_hooks(&mlx, &img);
  return (0);
}
