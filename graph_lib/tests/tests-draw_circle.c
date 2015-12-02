/*
** tests-draw_circle.c for tests in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 12:11:44 2014
** Last update Tue Oct 28 12:37:44 2014 
*/

#include <graph.h>

int		main(void)
{
  t_mlx		s_mlx;
  t_point	orig;

  if (!(s_mlx.mlx = mlx_init()))
    return (1);
  if (!(s_mlx.win = mlx_new_window(s_mlx.mlx, 10000, 10000, "lib tests\n")))
    return (2);
  orig.x = 300;
  orig.y = 300;
  draw_circle(&s_mlx, &orig, 200, 0x0FFF);
  while (1)
    ;
  mlx_loop(s_mlx.mlx);
  return (0);
}
