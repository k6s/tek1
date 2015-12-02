/*
** key_controls.c for my_select in /home/k6/epitech/MATHS/104intersection/my_select
** 
** Made by Chloe Cano
** Login   <k6@epitech.net>
** 
** Started on  Mon Jan  5 00:24:39 2015
** Last update Sun Jan 11 19:28:07 2015 
*/
#include <my_select.h>

void			ev_kup(t_menu_term *menu_term, int UN argc)
{
  tputs(tgetstr("ue", NULL), 1, &tput_putc);
  put_str_caps(&menu_term->entry, menu_term->col_size);
  cur_goto_cprev(menu_term->col_size);
  cur_goto_prev(menu_term);
  tputs(tgetstr("us", NULL), 1, &tput_putc);
  put_str_caps(&menu_term->entry, menu_term->col_size);
  cur_goto_cprev(menu_term->col_size);
}

void			ev_kdo(t_menu_term *menu_term, int UN argc)
{
  tputs(tgetstr("ue", NULL), 1, &tput_putc);
  put_str_caps(&menu_term->entry, menu_term->col_size);
  cur_goto_cprev(menu_term->col_size);
  cur_goto_next(menu_term);
  tputs(tgetstr("us", NULL), 1, &tput_putc);
  put_str_caps(&menu_term->entry, menu_term->col_size);
  cur_goto_cprev(menu_term->col_size);
  tputs(tgetstr("ue", NULL), 1, &tput_putc);
}

void			ev_selct(t_menu_term *menu_term, int UN argc)
{
  if (menu_term->entry->selected)
    menu_term->entry->selected = 0;
  else
    menu_term->entry->selected = 1;
  put_str_caps(&menu_term->entry, menu_term->col_size);
  cur_goto_cprev(menu_term->col_size);
}

void			ev_esc(t_menu_term UN *menu_term, UN int argc)
{
  tputs(tgetstr("te", NULL), 0, &tput_putc);
  return;
}

int			call_event(char *buff, t_menu_term *menu_term, int argc)
{
  int			n;
  const int		controls[K_NB] = {K_UP, K_DO, K_SELCT, K_ESC, K_DONE};
  const t_event_fp	event_fp[K_NB] = {ev_kup, ev_kdo, ev_selct, ev_esc, ev_done};

  n = 0;
  while ((n < K_NB) && (*(int *)buff != controls[n]))
    ++n;
  if (n == K_NB)
    return (0);
  event_fp[n](menu_term, argc);
  return (0);
}
