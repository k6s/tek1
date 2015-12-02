/*
** ia_move.c for allum-1 in /home/k6/rendu/allum-1
** 
** Made by Cano Chloe
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Feb 22 11:42:24 2015 Cano Chloe
** Last update Sun Feb 22 12:10:03 2015 Cano Chloe
*/
#include <allum-1.h>

int			do_move(int *pos_r, int *pos, unsigned int *map,
				t_point *margin)
{
  while (*pos_r != pos[0] + 1)
    ev_kdo(map, pos_r, 4, margin);
  return (ia_remove_allum(pos_r, pos[1], map, margin));
}

int			ia_move(int *pos_r, int nb_row, unsigned int *map,
				t_point *margin)
{
  unsigned char		count[4];
  unsigned int		pos[2];
  int			j;
  unsigned int		save_map;

  my_bzero(count, 4);
  if (!(pos[0] = 0) && (pos[1] = ia_last_moves(pos_r, nb_row, map, margin)))
    return (ia_remove_allum(pos_r, pos[1], map, margin));
  nim_sum_store(map, nb_row, (char *)count);
  while (pos[0] < nb_row && (pos[1] = -1))
    {
      save_map = map[pos[0]];
      while (++pos[1] <= save_map)
	{
	  map[pos[0]] = save_map - pos[1];
	  if (!(nim_sum(map, nb_row)))
	    {
	      map[pos[0]] = save_map;
	      return (do_move(pos_r, (int *)pos, map, margin));
	    }
	}
      map[pos[0]++] = save_map;
    }
  ev_kdo(map, pos_r, nb_row, margin);
  return (ia_remove_allum(pos_r, 1, map, margin));
}
