/*
** tests-img_put_pixel.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:58:30 2014
** Last update Tue Oct 28 14:18:17 2014 
*/

#include <graph.h>

int		main(void)
{
  t_mlx		s_mlx;
  t_img		s_img;
  t_point	pixel;

  s_mlx.win_size.x = 10000;
  s_mlx.win_size.y = 10000;
  if (!(s_mlx.mlx = mlx_init()))
    return (0);
  if (!(s_mlx.win = mlx_new_window(s_mlx.mlx, 10000, 10000, "test")))
    return (0);
  s_img.size.x = 10000;
  s_img.size.y = 10000;
  if (!(new_img(&s_mlx, &s_img)))
    return (0);
  pixel.x = 0;
  pixel.y = 0;
  img_put_pixel(&s_mlx, &s_img, &pixel, 0x00FFFFFF);
  mlx_put_image_to_window(s_mlx.mlx, s_mlx.win, s_img.img, 0, 0);
  mlx_loop(s_mlx.mlx);
  return (0);
}
