/*
** cur_goto.c for my_select in /home/cano_c/rendu/UNIX/my_select
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Jan 11 18:54:27 2015
** Last update Sun Jan 11 18:57:01 2015 
*/
#include <my_select.h>

void		cur_goto(t_point *pos, t_point *orig)
{
  tputs(tgoto(tgetstr("cm", NULL), pos->x + orig->x,
	      pos->y + orig->y), 1, &tput_putc) ;
}

void		cur_goto_menu(t_menu_term *menu_term)
{
  menu_term->pos.x = 0;
  menu_term->pos.y = 0;
  cur_goto(&menu_term->pos, &menu_term->orig);
}

void		cur_goto_next(t_menu_term *menu_term)
{
  if (menu_term->size.y - menu_term->pos.y - menu_term->orig.y < 2
      || menu_term->entry->next == menu_term->entries)
    {
      if (menu_term->entries == menu_term->entry->next)
	menu_term->pos.x = menu_term->orig.x;
      else
	menu_term->pos.x += 1 * menu_term->col_size;
      menu_term->pos.y = menu_term->orig.y;
    }
  else
    menu_term->pos.y += 1;
  cur_goto(&menu_term->pos, &menu_term->orig);
  menu_term->entry = menu_term->entry->next;
}

void		cur_goto_prev(t_menu_term *menu_term)
{
  if (menu_term->pos.y - menu_term->orig.y < 1
      || menu_term->entry == menu_term->entries)
    {
      if  (menu_term->entries == menu_term->entry)
	menu_term->pos.x = (menu_term->size.x - 1) * menu_term->col_size
	  + menu_term->orig.x;
      else
	menu_term->pos.x -= menu_term->col_size;
      if (menu_term->entry == menu_term->entries)
	{
	  menu_term->pos.y = menu_term->nb_entries % menu_term->size.y
	    + menu_term->orig.y;
	  if (!menu_term->pos.y)
	    menu_term->pos.y = menu_term->size.y - 1;
	  else
	    --menu_term->pos.y;
	}
      else
	menu_term->pos.y = menu_term->size.y - 1 + menu_term->orig.y;
    }
  else
    menu_term->pos.y -= 1;
  cur_goto(&menu_term->pos, &menu_term->orig);
  menu_term->entry = menu_term->entry->prev;
}

void			cur_goto_cprev(size_t len)
{
  while (len-- > 1)
    tputs(tgetstr("le", NULL), 1, &tput_putc);
}
