/*
** map.c for fdf in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Nov 19 17:31:00 2014
** Last update Sun Nov 23 23:18:44 2014 Cano Chloe
*/

#include <fdf.h>

static void	free_nb_tab(char **nb_tab)
{
  char		**p;

  p = nb_tab;
  while (*p)
    {
      free(*p);
      ++p;
    }
  free(nb_tab);
}

size_t		set_line_coord(t_fdf *s_fdf, char **p, size_t li)
{
  size_t	cco;
  t_3dpoint	coord;

  cco = -1;
  coord.y = li;
  while (*p && ++cco < s_fdf->len[X])
    {
      coord.x = cco;
      coord.z = my_getnbr(*p++);
      proj_iso(&coord, &s_fdf->map[li][cco], 20);
    }
  return (cco);
}

static t_point	**add_line(t_fdf *s_fdf, char *line, size_t li)
{
  char		**nb_tab;

  if (!(nb_tab = my_str_to_wordtab(line)))
    return ((void *)-1);
  free(line);
  set_x_len(s_fdf, nb_tab);
  if (!(s_fdf->map[li] = malloc(sizeof(s_fdf->map) * s_fdf->len[X])))
    return ((void *)-1);
  if (set_line_coord(s_fdf, nb_tab, li) != s_fdf->len[X] - 1)
    return (NULL);
  free_nb_tab(nb_tab);
  return (s_fdf->map);
}

t_point		**get_map(int fd, size_t li, t_fdf *s_fdf)
{
  char		*line;

  if ((line = get_next_line(fd)))
    if ((s_fdf->map = get_map(fd, li + 1, s_fdf)) == (void *)-1)
      return ((void *)-1);
  if (!line)
    {
      s_fdf->len[Y] = li;
      if (!(s_fdf->map = malloc(sizeof(*s_fdf->map) * (li + 1))))
	return ((void *)-1);
      s_fdf->map[li] = NULL;
    }
  else
    return (add_line(s_fdf, line, li));
  return (s_fdf->map);
}

void		free_map(t_point **map)
{
  t_point      	**p;

  p = map;
  while (*p)
    {
      free(*p);
      ++p;
    }
  free(map);
}
