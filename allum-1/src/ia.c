/*
** ia.c for allum-1 in /home/cano_c/rendu/ELEM/CPE_2014_allum1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Feb 22 11:09:12 2015
** Last update Sun Feb 22 12:05:44 2015 Cano Chloe
*/
#include <allum-1.h>

int			nim_sum(unsigned int *map, int nb_row)
{
  int			count[4];
  int			j;
  int			pos;

  my_bzero(count, sizeof(count[0]) * 4);
  pos = 0;
  while (pos < nb_row)
    {
      j = 0;
      while (j < 4)
	{
	  count[j] ^= (char)((map[pos] >> j) & 1);
	  ++j;
	}
      ++pos;
    }
  return (count[3] + count[2] * 2 + count[1] * 4 + count[0] * 8);
}

void			nim_sum_store(unsigned int *map, int nb_rw, char *count)
{
  int			pos;
  int			j;
  int			save_map;

  pos = 0;
  save_map = 0;
  while (pos < nb_rw)
    {
      j = 0;
      if (map[pos])
	++save_map;
      while (j < 4)
	{
	  count[j] ^= (char)((map[pos] >> j) & 1);
	  ++j;
	}
      ++pos;
    }
}

int			ia_map_report(int *desc_line, int *map, int nb_row)
{
  int			idx;

  idx = 0;
  desc_line[MUL_LINE] = 0;
  desc_line[SOL_LINE] = 0;
  while (idx < nb_row)
    {
      if (map[idx] == 1)
	++desc_line[SOL_LINE];
      else if (map[idx] > 1)
	{
	  desc_line[MUL_LINE_LEN] = map[idx];
	  ++desc_line[MUL_LINE];
	}
      ++idx;
    }
  return (desc_line[MUL_LINE]);
}

int			ia_last_moves(int *pos_r, int nb_row, unsigned int *map,
				      t_point *margin)
{
  int			idx;
  int			desc_line[3];

  if (!(ia_map_report(desc_line, map, nb_row)))
    {
      ev_kdo(map, pos_r, nb_row, margin);
      return (1);
    }
  else if (desc_line[MUL_LINE] == 1)
    {
      if (!desc_line[SOL_LINE])
	{
	  ev_kdo(map, pos_r, nb_row, margin);
	  return (desc_line[MUL_LINE_LEN] - 1);
	}
      else
	{
	  while (map[*pos_r - 1] < 2)
	    ev_kdo(map, pos_r, nb_row, margin);
	  if (desc_line[SOL_LINE] % 2)
	    return (desc_line[MUL_LINE_LEN]);
	  return (desc_line[MUL_LINE_LEN] - 1);
	}
    }
  return (0);
}
