/*
** output.c for bsq in /home/cano_c/rendu/ELEM/CPE_2014_bsq
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Jan  2 14:32:35 2015 
** Last update Mon Jan 12 15:20:49 2015 
*/
#include <bsq.h>

t_map		*map_error(t_map *s_map, int fd, char *msg)
{
  write(2, "Map error: ", 11);
  write(2, msg, my_strlen(msg));
  if (fd > 0)
    close(fd);
  free(s_map->map);
  free(s_map);
  return (NULL);
}

static void	print_square_line(t_square *s_square, size_t *co,
				  size_t *on_square)
{
  if (on_square[1] == s_square->size)
    on_square[0] = 0;
  else
    {
      while (*co - s_square->co < s_square->size)
	{
	  my_putchar('x');
	  ++(*co);
	}
      ++on_square[1];
    }
}

static void	print_map_char(t_map *s_map, size_t li, size_t *co)
{
  if (MAP_VAL(s_map, li, *co))
    my_putchar('o');
  else
    my_putchar('.');
  ++(*co);
}

void		print_map(t_map *s_map, t_square *s_square)
{
  size_t	li;
  size_t	co;
  size_t       	on_square[2];

  li = 0;
  on_square[0] = 0;
  on_square[1] = 0;
  while (li < s_map->li)
    {
      co = 0;
      if (s_square && li == s_square->li)
	on_square[0] = 1;
      while (co < s_map->co)
	{
	  if (s_square && on_square[0] && co == s_square->co)
	    print_square_line(s_square, &co, on_square);
	  else
	    print_map_char(s_map, li, &co);
	}
      my_putchar('\n');
      ++li;
    }
}

t_square        *square_error(t_map *s_map, t_square *s_square, char *err_msg)
{
  free(s_map->map);
  free(s_map);
  free(s_square);
  write(2, "Error while solving map: ", 25);
  write(2, err_msg, my_strlen(err_msg));
  write(2, "\n", 1);
  return (NULL);
}
