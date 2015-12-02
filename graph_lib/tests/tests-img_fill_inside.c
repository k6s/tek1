/*
** tests-draw_circle.c for tests in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:11:44 2014
** Last update Tue Oct 28 18:35:42 2014 
*/

#include <graph.h>
#include <stdlib.h>

int		main(void)
{
  t_mlx		*s_mlx;
  t_img		*img;
  t_point	orig[2];
  unsigned long	colors[2];

  if (!(s_mlx = malloc(sizeof(*s_mlx))))
    return (0);
  if (!(img = malloc(sizeof(*img))))
    return (0);
  if (!(s_mlx->mlx = mlx_init()))
    return (1);
  if (!(s_mlx->win = mlx_new_window(s_mlx->mlx, 10000, 10000, "lib tests\n")))
    return (2);
  img->size.x = 10000;
  img->size.y = 10000;
  if (!(new_img(s_mlx, img)))
    return (3);
  orig[0].x = 300;
  orig[0].y = 300;
  orig[1].x = 100;
  orig[1].y = 300;
  colors[1] = 0x00FFFFFF;
  colors[0] = 0x0000FF00;
img_put_circle(s_mlx, img, orig, 0x00FFFFFF);
/*img_put_line(s_mlx, img, orig, colors[1]);
orig[1].y = 500;
orig[1].x = 300;
img_put_line(s_mlx, img, orig, colors[1]);
orig[0].y = 500;
orig[1].y = 500;
orig[1].x = 500;
img_put_line(s_mlx, img, orig, colors[1]);
orig[0].x = 500;
orig[0].y = 300;
orig[1].x = 500;
orig[1].y = 500;
img_put_line(s_mlx, img, orig, colors[2]); */
  mlx_put_image_to_window(s_mlx->mlx, s_mlx->win, img->img, 0, 0);
  orig[0].x = 320;
  orig[0].y = 300;
  img_fill_inside(s_mlx, img, &orig[0], colors);
  mlx_put_image_to_window(s_mlx->mlx, s_mlx->win, img->img, 0, 0);
  mlx_loop(s_mlx->mlx);
  return (0);
}
