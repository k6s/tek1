/*
** square.c for bsq in /home/cano_c/rendu/ELEM/CPE_2014_bsq
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Jan  2 14:32:35 2015
** Last update Sun Jan 18 22:05:23 2015 
*/
#include <bsq.h>

size_t		get_tok(t_map *s_map, size_t li, size_t co, size_t *tok)
{
  size_t	min;

  if (MAP_VAL(s_map, li, co))
    return (0);
  if (li == s_map->li - 1 || co == s_map->co - 1)
    return (1);
  else
    {
      min = tok[li * s_map->co + (co + 1)];
      if (min > tok[(li + 1) * s_map->co + co])
	min = tok[(li + 1) * s_map->co + co];
      if (min > tok[li + 1] * s_map->co + (co + 1))
	min = tok[(li + 1) * s_map->co + (co + 1)];
      return (min + 1);
    }
  return (0);
}

void            get_biggest_square(t_map *s_map, t_square *s_square, ssize_t li,
				   ssize_t co)
{
  size_t       	*tok;

  if (!(tok = malloc(sizeof(*tok) * s_map->li * s_map->co)))
    return ;
  while (li >= 0)
    {
      co = s_map->co - 1;
      while (co >= 0)
	{
	  if ((tok[li * s_map->co + co] = get_tok(s_map, li, co, tok))
	      >= s_square->size)
	  {
	    s_square->size = tok[li * s_map->co + co];
	    s_square->li = li;
	    s_square->co = co;
	  }
	  --co;
	}
      --li;
    }
  free(tok);
}

t_square        *find_square(t_map *s_map)
{
  t_square      *s_square;

  if (!(s_square = malloc(sizeof(*s_square))))
    return (square_error(s_map, s_square, "out of memory"));
  s_square->size = 0;
  get_biggest_square(s_map, s_square, s_map->li - 1, s_map->co - 1);
  return (s_square);
}
