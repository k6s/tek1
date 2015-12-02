/*
** ev_done.c for my_select in /home/cano_c/rendu/UNIX/my_select
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Jan 11 19:38:58 2015
** Last update Sun Jan 11 19:41:06 2015 
*/
#include <my_select.h>

static void		next_free(t_select **c_entry)
{
  t_select		*tmp;

  tmp = *c_entry;
  *c_entry = (*c_entry)->next;
  free(tmp);
}

static void		print_selected(t_select **c_entry, t_select **m_entries)
{
  char			prev;

  prev = 0;
  if ((*c_entry)->selected && (prev = 1))
    my_putstr((*c_entry)->entry);
  next_free(c_entry);
  while (*c_entry != *m_entries)
    {
      if ((*c_entry)->selected)
	{
	  if (prev)
	    my_putchar(' ');
	  my_putstr((*c_entry)->entry);
	  prev = 1;
	}
      next_free(c_entry);
    }
  my_putchar('\n');
}

void			ev_done(t_menu_term *menu_term, int UN argc)
{
  t_select		**c_entry;
  t_select		**m_entries;

  tputs(tgetstr("te", NULL), 1, &tput_putc);
  c_entry = &menu_term->entry;
  m_entries = &menu_term->entries;
  while (*c_entry != *m_entries)
    {
      *c_entry = (*c_entry)->prev;
      tputs(tgetstr("up", NULL), 1, &tput_putc);
    }
  erase_menu_entry(menu_term->col_size);
  tputs(tgetstr("cd", NULL), 1, &tput_putc);
  print_selected(c_entry, m_entries);
}
