/*
** select_row.c for allum-1 in /home/k6/epitech/ELEM/allum-1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Feb 13 22:09:32 2015
** Last update Sun Feb 22 12:07:20 2015 Cano Chloe
*/
#include <allum-1.h>

int				ev_kup(int *map, int *pos_r, int nb_row,
				       t_point *margin)
{
  int				n;

  write(1, "  ", 2);
  if (*pos_r > 1)
    {
      n = 1;
      while (*pos_r - n && !map[*pos_r - n - 1])
	++n;
      if (*pos_r - n)
	{
	  select_line(*pos_r - n, margin, pos_r);
	  return (0);
	}
    }
  n = 0;
  while (nb_row - n > 0 && !map[nb_row - n - 1])
    ++n;
  select_line(nb_row - n, margin, pos_r);
  return (0);
}

int				ev_kdo(int *map, int *pos_r, int nb_row,
				       t_point *margin)
{
  int				n;

  write(1, "  ", 2);
  if (*pos_r < nb_row)
    {
      n = 1;
      while (*pos_r + n <= nb_row && !map[*pos_r + n - 1])
	++n;
      if (*pos_r + n <= nb_row)
	{
	  select_line(*pos_r + n, margin, pos_r);
	  return (0);
	}
    }
  n = 1;
  while (n <= nb_row && !map[n - 1])
    ++n;
  select_line(n, margin, pos_r);
  return (0);
}

int			select_row(int *map, int *pos_r, int nb_row,
				   t_point *margin)
{
  int			buff;

  tputs(tgetstr("vi", NULL), 0, &tput_putc);
  buff = 0;
  while (read(0, (char *)(&buff), 4) > 0 && buff != K_DONE && buff != K_ESC)
    {
      if (buff == K_UP)
	ev_kup(map, pos_r, nb_row, margin);
      else if (buff == K_DO)
	ev_kdo(map, pos_r, nb_row, margin);
      buff = 0;
    }
  return (buff == K_ESC ? 0 : *pos_r);
}
