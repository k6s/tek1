/*
** fdf.h for fdf in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Nov 18 17:01:07 2014
** Last update Sun Nov 23 23:08:06 2014 
*/

#ifndef FDF_H_
# define FDF_H_

# include <graph.h>
# include <my.h>
# include <get_next_line.h>

# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# define CTE	1

typedef struct		s_fdf
{
  t_point		**map;
  size_t		len[2];
  int			ratio;
} t_fdf;

int		fdf(t_fdf *map);

/*
** map.c
*/
t_point		**get_map(int fd, size_t li, t_fdf *s_fdf);
void		free_map(t_point **map);

/*
** dips_utils.c
*/
void		get_ratio(t_img *img, size_t *ratio, size_t co, size_t li);
void		get_min(t_fdf *s_fdf, t_point *min_max);
void		make_line(t_point *line, t_point *p1, t_point *p2,
			  t_point *offset);
void		get_offset(t_fdf *s_fdf, t_point *offset, t_mlx *mlx);

/*
** events.c
*/
int		handle_key(int keycode, void *param);
int		handle_expose(void *param);

#endif /* !FDF_H_ */
