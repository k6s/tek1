/*
** main.c for my_select in /home/k6/epitech/MATHS/104intersection/my_select
** 
** Made by Chleo Cano
** Login   <k6@epitech.net>
** 
** Started on  Mon Jan  5 00:06:37 2015
** Last update Sun Jan 11 19:00:52 2015 
*/
#include <my_select.h>

int			tput_putc(int c)
{
  my_putchar((char)c);
  return (1);
}

static int		read_kinput(t_menu_term *menu_term, int argc)
{
  char			buff[4];
  int			ret;

  my_bzero(buff, 4);
  while ((ret = read(0, buff, 5)) != 27)
    {
      call_event(buff, menu_term, argc);
      if (*(int *)buff == K_ESC || *(int *)buff == K_DONE)
	{
	  tc_reset(menu_term->term_save);
	  exit(0);
	}
      my_bzero(buff, 4);
    }
  return (ret);
}

static void		get_menu_format(t_menu_term *menu_term)
{
  menu_term->size.y = menu_term->nb_entries / menu_term->ws.ws_col;
  menu_term->size.y += menu_term->nb_entries % menu_term->ws.ws_col;
  menu_term->size.x = menu_term->nb_entries / menu_term->size.y;
  ioctl(0, TIOCGWINSZ, &menu_term->ws);
}

static void		menu_init(t_select **m_entries, t_select **c_entry,
				  int argc, t_menu_term *menu_term)
{
  menu_term->nb_entries = argc - 1;
  get_menu_format(menu_term);
  *c_entry = *m_entries;
  while ((*c_entry)->next)
    *c_entry = (*c_entry)->next;
  (*c_entry)->next = *m_entries;
  (*m_entries)->prev = *c_entry;
  *c_entry = *m_entries;
  tputs(tgetstr("ti", NULL), 1, &tput_putc);
  menu_term->orig.x = 0;
  menu_term->orig.y = 0;
  menu_term->pos.x = 0;
  menu_term->pos.y = 0;
  selem_print(menu_term);
  cur_goto_menu(menu_term);
}

int			main(int argc, char **argv, char **environ)
{
  t_menu_term		menu_term;
  struct termios	term;
  int			n;
  int			ret;

  if (argc > 1)
    {
      n = 1;
      menu_term.col_size = 0;
      if (!(menu_term.term_save = tc_init(&term, environ)))
	return (-2);
      menu_term.entries = NULL;
      while (n < argc)
	{
	  selem_pushback(new_selem(argv[n]), &menu_term.entries,
			 &menu_term.col_size);
	  ++n;
	}
      ++menu_term.col_size;
      menu_init(&menu_term.entries, &menu_term.entry, argc, &menu_term);
      ret = read_kinput(&menu_term, argc);
      tc_reset(menu_term.term_save);
    }
  return (ret);
}
