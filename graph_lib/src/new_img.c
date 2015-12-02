/*
** new_img.c for graph lib in /home/cano_c/rendu/IGRAPH/lib
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 28 14:27:32 2014
** Last update Tue Oct 28 14:36:42 2014 
*/
#include <graph.h>

int		new_img(t_mlx *s_mlx, t_img *s_img)
{
  if (!(s_img->img = mlx_new_image(s_mlx->mlx, s_img->size.x, s_img->size.y)))
    return (0);
  if (!(s_img->data = mlx_get_data_addr(s_img->img, &s_img->bpp,
					&s_img->size_line, &s_img->endian)))
    return (0);
  return (1);
}
