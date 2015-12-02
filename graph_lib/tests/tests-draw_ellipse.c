/*
** tests-draw_ellipse.c for tests in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:11:44 2014
** Last update Tue Oct 28 12:43:06 2014 
*/

#include <graph.h>

int		main(void)
{
  t_mlx		s_mlx;
  t_point	orig;
  int		r[2];

  if (!(s_mlx.mlx = mlx_init()))
    return (1);
  if (!(s_mlx.win = mlx_new_window(s_mlx.mlx, 10000, 10000, "lib tests\n")))
    return (2);
  orig.x = 300;
  orig.y = 300;
  r[0] = 200;
  r[1] = 100;
  draw_ellipse(&s_mlx, &orig, r, 0x0FFF);
  while (1)
    ;
  mlx_loop(s_mlx.mlx);
  return (0);
}
