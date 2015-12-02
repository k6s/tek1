/*
** curses.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Apr  9 15:49:19 2015
** Last update Thu Apr  9 22:31:05 2015 
*/
#include <vm.h>

void		dump_line(unsigned char *arena, size_t idx, WINDOW *win)
{
  size_t	i;
  const char	*base = "0123456789abcdef";

  i = 0;
  while (i < 64)
    {
      waddch(win, base[*(arena + i + idx) / 16]);
      waddch(win, base[*(arena + i + idx) % 16]);
      waddch(win, ' ');
      ++i;
    }
}

WINDOW		**get_wins(void)
{
  WINDOW	**wins;

  if (!(wins = malloc(sizeof(*wins) * NB_WINS)))
    return (NULL);
  if (!(initscr()))
    return (NULL);
  noecho();
  nl();
  wins[WIN_MAIN] = newwin(1000, 1000, 0, 0);
  wins[WIN_ARENA] = subwin(wins[WIN_MAIN], 700, 700, 0, 0);
  return (wins);
}

static void	set_wins_color(WINDOW **wins)
{
  start_color();
  use_default_colors();
  init_pair(1, COLOR_WHITE, -1);
  init_pair(2, COLOR_RED, -1);
  init_pair(3, COLOR_CYAN, -1);
  init_pair(4, COLOR_GREEN, -1);
  wattron(wins[WIN_ARENA], COLOR_PAIR(1));
}

WINDOW		**curses_init(void)
{
  WINDOW	**wins;

  if (!(wins = get_wins()))
    return (NULL);
  set_wins_color(wins);
  return (wins);
}
