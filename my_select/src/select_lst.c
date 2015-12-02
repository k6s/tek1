/*
** select_lst.c for my_select in /home/k6/epitech/MATHS/104intersection/my_select
** 
** Made by Chloe Cano
** Login   <k6@epitech.net>
** 
** Started on  Mon Jan  5 00:15:42 2015
** Last update Sun Jan 11 18:53:25 2015 
*/
#include <my_select.h>

t_select	*new_selem(char *entry)
{
  t_select	*new;

  if ((new = my_memalloc(sizeof(*new))))
      new->entry = entry;
  return (new);
}

void		selem_pushback(t_select *entry, t_select **orig,
			       size_t *co_size)
{
  t_select	*tmp;
  size_t	len;

  if (*orig)
    {
      tmp = *orig;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = entry;
      entry->prev = tmp;
    }
  else
      *orig = entry;
  len = my_strlen(entry->entry);
  if (len > *co_size)
    *co_size = len;
  entry->len = len;
}

void		screen_too_small(t_menu_term *menu_term)
{
  cur_goto_menu(menu_term);
  tputs(tgetstr("cs", NULL), 1, &tput_putc);
  write(2, " Screen too small\n", 18);
}

char		check_screen_size(t_menu_term *menu_term)
{
  menu_term->size.y = (ssize_t)menu_term->nb_entries > menu_term->ws.ws_row
    - menu_term->orig.y ? menu_term->ws.ws_row : menu_term->nb_entries;
  menu_term->size.x = (ssize_t)menu_term->nb_entries
    / menu_term->size.y + (menu_term->nb_entries % menu_term->size.y ? 1 : 0);
  if ((ssize_t)menu_term->size.x * menu_term->col_size
      > menu_term->ws.ws_col - menu_term->orig.x)
    return (0);
  return (1);
}

int		selem_print(t_menu_term *menu_term)
{
  int		ret;

  ret = 0;
  cur_goto_menu(menu_term);
  if (!(check_screen_size(menu_term)))
    screen_too_small(menu_term);
  else
    {
      my_putstr(menu_term->entry->entry);
      ++ret;
      cur_goto_next(menu_term);
      while (menu_term->entry != menu_term->entries)
	{
	  my_putstr(menu_term->entry->entry);
	  ++ret;
	  cur_goto_next(menu_term);
	}
    }
  return (ret);
}
