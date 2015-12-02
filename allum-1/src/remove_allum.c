/*
** remove_allum.c for allum-1 in /home/k6/epitech/ELEM/allum-1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Feb 13 22:54:24 2015
** Last update Sun Feb 22 12:09:09 2015 Cano Chloe
*/
#include <allum-1.h>

static int		get_user_entry(int *pos_r, int nb_row, int *map,
				       t_point *margin)
{
  int			to_rm;
  int			buff;
  t_point		pos;
  const char		*msg = "combien d allumettes ? ";

  pos.x = margin->x - 4;
  pos.y = nb_row + 2 + margin->y;
  ask_user_input(msg, &pos, 1);
  buff = 0;
  to_rm = 0;
  pos.x += my_strlen(msg);
  while (to_rm < 1 || to_rm > map[*pos_r - 1])
    {
      to_rm = 0;
      buff = 0;
      cur_goto(&pos);
      tputs(tgetstr("ce", NULL), 0, &tput_putc);
      if ((to_rm = term_getunbr(INT_MAX)) < 0)
	return (to_rm);
    }
  return (to_rm);
}

static void		rm_an_allum(int *pos_r, int nb_row, int *map,
				    t_point *margin)
{
  t_point		pos;

  pos.y = *pos_r - 1 + margin->y;
  if (!(map[*pos_r - 1] % 2))
    pos.x = margin->x + nb_row - 1 - map[*pos_r - 1] / 2;
  else
    pos.x = margin->x + nb_row - 1 + map[*pos_r - 1] / 2;
  cur_goto(&pos);
  write(1, " ", 1);
  --map[*pos_r - 1];
}

static int		select_next_line(int *pos_r, int nb_row, int *map,
					 t_point *margin)
{
  t_point		pos;

  pos.y = *pos_r - 1 + margin->y;
  pos.x = margin->x - 4;
  cur_goto(&pos);
  write(1, "  ", 2);
  if (!end_game(map, nb_row))
    {
      ev_kup(map, pos_r, nb_row, margin);
      return (0);
    }
  return (1);
}

int			ia_remove_allum(int *pos_r, int to_rm,
					int *map, t_point *margin)
{
  int			buff;
  t_point		pos;
  int			nb_row;

  buff = -1;
  nb_row = 4;
  pos.x = margin->x - 4;
  pos.y = nb_row + 2 + margin->y;
  cur_goto(&pos);
  tputs(tgetstr("ce", NULL), 0, &tput_putc);
  while (++buff < to_rm)
    rm_an_allum(pos_r, nb_row, map, margin);
  return (select_next_line(pos_r, nb_row, map, margin));
}

int			remove_allum(int *pos_r, int nb_row, int *map,
				     t_point *margin)
{
  int			buff;
  t_point		pos;
  int			to_rm;

  if ((to_rm = get_user_entry(pos_r, nb_row, map, margin)) < 1)
    return (-1);
  buff = -1;
  pos.x = margin->x - 4;
  pos.y = nb_row + 2 + margin->y;
  cur_goto(&pos);
  tputs(tgetstr("ce", NULL), 0, &tput_putc);
  while (++buff < to_rm)
    rm_an_allum(pos_r, nb_row, map, margin);
  tputs(tgetstr("vi", NULL), 0, &tput_putc);
  return (select_next_line(pos_r, nb_row, map, margin));
}
