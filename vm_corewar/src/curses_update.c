/*
** curse_update.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Apr  9 22:04:09 2015
** Last update Fri Apr 10 15:49:45 2015 
*/
#include <vm.h>

void			dump_var(WINDOW *win, unsigned char *var, size_t len)
{
  const char		*base = "0123456789abcdef";

  while (len--)
    {
      waddch(win, base[*var / 16]);
      waddch(win, base[*(var++) % 16]);
      waddch(win, ' ');
    }
}

t_lst			*dump_clvar(WINDOW *win, char *arena,
				   char *v, size_t len)
{
  size_t		x;
  size_t		end;
  t_lst			*new;
  unsigned char		*var;

  var = (unsigned char *)v;
  if (!(new = new_lst(0)))
    return (NULL);
  new->len = len;
  new->data = var;
  wattron(win, A_BOLD);
  x = (var - (unsigned char *)arena) % 64;
  end = (len + x) / 64 ? (len + x) % 64 : 0;
  wmove(win, ((var - (unsigned char *)arena) % MEM_SIZE) / 64, x * 3);
  dump_var(win, var, len - end);
  wmove(win, ((var - (unsigned char *)arena) % MEM_SIZE) / 64 + 1, x * 3);
  dump_var(win, var + len - end, end);
  wattroff(win, A_BOLD);
  return (new);
}

void			restore_lvar(WINDOW *win, char *arena,
				     char *var, size_t len)
{
  size_t		x;
  size_t		end;

  wattron(win, COLOR_PAIR(1));
  wattron(win, A_BOLD);
  x = (var - arena) % 64;
  end = (len + x) / 64 ? (len + x) % 64 : 0;
  wmove(win, (var - arena) / 64, x * 3);
  wchgat(win, (len - end) * 3, COLOR_PAIR(2), 1, 0);
  wmove(win, (var - arena) / 64 + 1, x * 3);
  wchgat(win, end * 3, COLOR_PAIR(2), 1, 0);
  wattron(win, A_BOLD);
}

void			update_win(WINDOW *win, unsigned char *arena,
				   unsigned char *dst, size_t len)
{
  dump_clvar(win, (char *)arena, (char *)dst, len);
  restore_lvar(win, (char *)arena, (char *)dst, len);
  wrefresh(win);
}
