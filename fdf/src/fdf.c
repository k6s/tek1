/*
** fdf.c for fdf in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Nov 19 17:47:43 2014
** Last update Sun Nov 23 23:37:30 2014 Cano Chloe
*/

#include <fdf.h>

int		open_window(t_mlx *s_mlx, char *title)
{
  if (!(s_mlx->mlx = mlx_init()))
    return (-1);
  if (!(s_mlx->win = mlx_new_window(s_mlx->mlx, s_mlx->win_size.x,
				    s_mlx->win_size.y, title)))
    return (-1);
  return (0);
}

void		fdf_to_img(t_fdf *s_fdf, t_img *img, t_mlx *mlx)
{
  size_t	pos_x;
  size_t	pos_y;
  t_point	line[2];
  t_point	offset;

  pos_y = -1;
  get_offset(s_fdf, &offset, mlx);
  while (++pos_y < s_fdf->len[Y] && (pos_x = -1))
  {
      while (++pos_x < s_fdf->len[X])
	{
	  if (pos_x < s_fdf->len[X] - 1)
	    {
	      make_line(line, &s_fdf->map[pos_y][pos_x],
			&s_fdf->map[pos_y][pos_x + 1], &offset);
	      img_put_line(mlx, img, line, 0x00FFFFFF);
	    }
	  if (pos_y < s_fdf->len[Y] - 1)
	    {
	      make_line(line, &s_fdf->map[pos_y][pos_x],
			&s_fdf->map[pos_y + 1][pos_x], &offset);
	      img_put_line(mlx, img, line, 0x00FFFFFF);
	    }
	}
    }
}

void		get_fdf_img(t_mlx *mlx, t_img *img, t_fdf *s_fdf)
{
  size_t       	ratio;

  if (s_fdf->len[Y] < 1 || s_fdf->len[X] < 1)
    exit(1);
  get_ratio(img, &ratio, s_fdf->len[X], s_fdf->len[Y]);
  fdf_to_img(s_fdf, img, mlx);
}

int		fdf(t_fdf *s_fdf)
{
  t_mlx		s_mlx;
  t_img		s_img;
  t_expose	s_expose;

  s_mlx.win_size.x = 800;
  s_mlx.win_size.y = 500;
  if ((open_window(&s_mlx, "fdf")) < -1)
    return (-1);
  s_img.size.x = s_mlx.win_size.x;
  s_img.size.y = s_mlx.win_size.y;
  s_img.pos.x = 0;
  s_img.pos.y = 0;
  if (!(new_img(&s_mlx, &s_img)))
    return (-1);
  get_fdf_img(&s_mlx, &s_img, s_fdf);
  mlx_put_image_to_window(s_mlx.mlx, s_mlx.win, s_img.img, 0, 0);
  s_expose.mlx = &s_mlx;
  s_expose.img = &s_img;
  mlx_expose_hook(s_mlx.win, &handle_expose, &s_expose);
  mlx_key_hook(s_mlx.win, &handle_key, s_fdf);
  mlx_loop(s_mlx.mlx);
  return (0);
}
