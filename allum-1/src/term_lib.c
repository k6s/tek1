/*
** term_lib.c for allum-1 in /home/k6/epitech/ELEM/allum-1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Feb 13 22:55:47 2015
** Last update Sun Feb 22 12:07:59 2015 Cano Chloe
*/
#include <term.h>

struct termios		*term_raw(char **environ)
{
  struct termios	term;
  struct termios	*term_save;
  char			*name;
  const char		*def_name = "linux";
  char			buff[2048];

  if (!(name = my_getenv(environ, "TERM=")))
    name = (char *)def_name;
  if (tgetent((char *)buff, name) < 1)
    return (NULL);
  if (tcgetattr(0, &term))
    return (NULL);
  if (!(term_save = malloc(sizeof(*term_save))))
    return (NULL);
  my_memcpy(term_save, &term, sizeof(*term_save));
  term.c_lflag &= ~(ICANON | ECHO);
  if (tcsetattr(0, TCSANOW, &term))
    return (NULL);
  return (term_save);
}

int			tput_putc(int c)
{
  return (write(1, (char *)(&c), 1));
}

void			cur_goto(t_point *pos)
{
  tputs(tgoto(tgetstr("cm", NULL), pos->x, pos->y), 1, &tput_putc);
}

void			select_line(int line, t_point *margin, int *pos_r)
{
  t_point		pos;

  *pos_r = line;
  pos.y = line - 1 + margin->y;
  pos.x = margin->x - 4;
  cur_goto(&pos);
  write(1, "->", 2);
  tputs(tgetstr("le", NULL), 0, &tput_putc);
  tputs(tgetstr("le", NULL), 0, &tput_putc);
}

long long      		term_getunbr(long long max)
{
  int			buff;
  int			to_rm;

  buff = 0;
  to_rm = 0;
  while (buff != K_DONE && buff != K_ESC)
    {
      buff = 0;
      if (read(0, (char *)(&buff), 4) < 1)
	return (-1);
      if (buff >= '0' && buff <= '9')
	{
	  if (to_rm * 10 + buff - '0' < INT_MAX)
	    {
	      write(1, (char *)(&buff), 1);
	      to_rm *= 10;
	      to_rm += buff - '0';
	    }
	}
    }
  return (buff == K_ESC ? : to_rm);
}
