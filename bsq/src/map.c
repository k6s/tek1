/*
** map.c for bsq in /home/cano_c/rendu/ELEM/CPE_2014_bsq
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec 22 20:02:31 2014
** Last update Mon Jan 12 15:10:03 2015 
*/
#include <bsq.h>

static char		is_valid_num(char *line)
{
  char		is_num;

  is_num = 0;
  while (*line)
    {
      if (*line < '0' || *line > '9')
	return (0);
      if (*line > '0')
	is_num = 1;
      ++line;
    }
  return (is_num);
}

static size_t		get_line_number(int fd)
{
  char		*line;
  size_t	li;

  li = 0;
  if ((line = get_next_line(fd)))
    {
      if ((is_valid_num(line)))
	li = my_getnbr(line);
      free(line);
    }
  return (li);
}

static char		add_line(t_map *s_map, size_t li, char *line, int fd)
{
  size_t	co;
  char		p;

  co = 0;
  while (line[co] && co < s_map->co)
    {
      if (line[co] == '.')
	p = 0;
      else if (line[co] == 'o')
	p = 1 << co % 8;
      else
	{
	  map_error(s_map, fd, "valid character are '.' or 'o'\n");
	  return (0);
	}
      s_map->map[li * s_map->sizeline + co / 8] |= p;
      ++co;
    }
  if (co != s_map->co || line[co])
    {
      map_error(s_map, fd, "invalid column lenght\n");
      return (0);
    }
  return (1);
}

static t_map		*fill_map(int fd, t_map *s_map)
{
  char			*line;
  size_t		li;

  if (!(line = get_next_line(fd)))
    return (map_error(s_map, fd, "invalid number of line in map.\n"));
  s_map->co = my_strlen(line);
  s_map->sizeline = s_map->co / 8 + (s_map->co % 8 ? 1 : 0);
  if (!(s_map->map = malloc(sizeof(*s_map->map) * s_map->li * s_map->sizeline)))
    return (map_error(s_map, fd, "Out of memory\n"));
  li = 0;
  my_bzero(s_map->map, sizeof(*s_map->map) * s_map->li * s_map->sizeline);
  if (!(add_line(s_map, li++, line, fd)))
    return (NULL);
  free(line);
  while ((line = get_next_line(fd)))
    {
      if (li < s_map->li)
        if (!add_line(s_map, li, line, fd))
          return (NULL);
      free(line);
      ++li;
    }
  if (li != s_map->li)
    return (map_error(s_map, fd, "specified line number and number of \
line in file don't match\n"));
  return (s_map);
}

t_map			*read_map(char *path)
{
  int			fd;
  t_map			*s_map;

  if (!(s_map = malloc(sizeof(*s_map))))
    {
      write(2, "No more memory available\n", 24);
      exit(-2);
    }
  s_map->map = NULL;
  if ((fd = open(path, O_RDONLY)) > -1)
    {
      if ((s_map->li = get_line_number(fd)) < 1)
	return (map_error(s_map, fd, "invalid line number\n"));
    }
  else
    return (map_error(s_map, fd, "cannot open file\n"));
  s_map = fill_map(fd, s_map);
  close(fd);
  return (s_map);
}
