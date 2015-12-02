/*
** choose_mode.c for allum-1 in /home/cano_c/rendu/ELEM/CPE_2014_allum1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Feb 17 11:25:32 2015
** Last update Sun Feb 22 12:15:33 2015 Cano Chloe
*/
#include <allum-1.h>

void			print_menu(t_point *orig, int nb_entries,
				   const char **entries)
{
  int			idx;
  t_point		pos;

  pos.x = orig->x;
  pos.y = orig->y;
  while (pos.y - orig->y < nb_entries)
    {
      idx = pos.y - orig->y;
      cur_goto(&pos);
      write(1, entries[idx], my_strlen(entries[idx]));
      ++pos.y;
    }
}

int			malloc_mode(int **map, char ***entries)
{
  if (!(*map = malloc(sizeof(*map) * 2)))
    return (-1);
  if (!(*entries = malloc(sizeof(*entries) * 2)))
    return (-1);
  if (!((*entries)[0] = my_strdup("Player vs Player")))
    return (-1);
  if (!((*entries)[1] = my_strdup("Player vs Computer")))
    return (-1);
  return (0);
}

int			choose_mode(t_point *margin)
{
  t_point		pos;
  int			pos_r;
  int			*map;
  int			mode;
  char			**entries;

  if (malloc_mode(&map, &entries))
    return (-1);
  map[0] = MODE_PVC;
  map[1] = MODE_PVP;
  print_menu(margin, 2, (const char **)entries);
  pos_r = 2;
  if ((mode = select_row(map, &pos_r, 2, margin)) > -1)
    mode = map[pos_r - 1];
  pos.x = margin->x;
  pos.y = margin->y;
  cur_goto(&pos);
  tputs(tgetstr("cd", NULL), 0, &tput_putc);
  free(map);
  free(entries[0]);
  free(entries[1]);
  free(entries);
  return (mode);
}
