/*
** menu_entry.c for my_select in /home/cano_c/rendu/UNIX/my_select
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Jan 11 19:07:13 2015
** Last update Sun Jan 11 19:07:38 2015 
*/
#include <my_select.h>

void			erase_menu_entry(int col_size)
{
  size_t		len;

  len = col_size;
  while (len-- > 1)
    {
      tputs(tgetstr("ce", NULL), 1, &tput_putc);
      tputs(tgetstr("ri", NULL), 1, &tput_putc);
    }
}

void			put_str_caps(t_select **c_entry, int col_size)
{
  int			ret;

  if (!(*c_entry)->selected)
    ret = my_putstr((*c_entry)->entry);
  else
    {
      tputs(tgetstr("mr", NULL), 1, &tput_putc);
      ret = my_putstr((*c_entry)->entry);
      ret = my_strlen((*c_entry)->entry);
      tputs(tgetstr("me", NULL), 1, &tput_putc);
    }
  while (ret < col_size - 1)
    {
      write(1, " ", 1);
      ++ret;
    }
}
