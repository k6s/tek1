/*
** select_termcap.c for my_select in /home/cano_c/rendu/UNIX/my_select
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Jan 11 19:18:30 2015
** Last update Sun Jan 11 19:27:16 2015 
*/
#include <my_select.h>

static void		tcfatal(int ret)
{
  write(2, "./my_select: cannot initialize termcaps\n", 40);
  exit(ret);
}

struct termios		*tc_init(struct termios *term, char **environ)
{
  char			t_buff[2048];
  struct termios	*tsave;

  if (environ)
    {
      if ((tgetent(t_buff, my_getenv(environ, "TERM="))) < 1)
	tcfatal(-1);
    }
  else
    if (tgetent(t_buff, "xterm") < 1)
      tcfatal(-1);
  if ((tcgetattr(0, term)) < 0)
    tcfatal(-2);
  if (!(tsave = malloc(sizeof(*tsave))))
    return (NULL);
  my_memcpy(tsave, term, sizeof(*tsave));
  term->c_lflag &= ~(ICANON);
  term->c_lflag &= ~(ECHO);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, term)) < 0)
    tcfatal(-3);
  return (tsave);
}


void			tc_reset(struct termios *term)
{
  tcsetattr(0, 0, term);
}
