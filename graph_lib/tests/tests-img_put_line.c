/*
** tests-img_put_line.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 14:28:49 2014
** Last update Wed Oct 29 15:54:02 2014 
*/

#include <graph.h>

int		main(void)
{
  t_mlx		mlx;
  t_img		img;
  t_point	line[2];

  if (!(mlx.mlx = mlx_init()))
    return (0);
  if (!(mlx.win = mlx_new_window(mlx.mlx, 10000, 10000, "test")))
    return (0);
  img.size.x = 10000;
  img.size.y = 10000;
  line[0].x = 0;
  line[1].x = 100;
  line[0].y = 0;
  line[1].y = 0;
  if (!(new_img(&mlx, &img)))
    return (0);
  img_put_line(&mlx, &img, line, 0x00FFFFFF);
  line[0].x = 1;
  line[0].y = 100;
  line[1].x = 1;
  line[1].y = 1;
  img_put_line(&mlx, &img, line, 0x00FFFFFF);
  mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
  mlx_loop(mlx.mlx);
  return (0);
}
