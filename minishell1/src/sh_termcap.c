/*
** sh_termcap.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 19 16:22:21 2015
** Last update Tue Feb  3 11:57:24 2015 
*/
#include <minishell1.h>

int			tput_putc(int i)
{
  return (write(1, &i, sizeof(i)));
}

void			restore_termcap(struct termios *tsave)
{
  tcsetattr(0, TCSANOW | TCSAFLUSH, tsave);
}

static int		my_tcsetattr(int fd, int opts, struct termios *term)
{
  if (tcsetattr(fd, opts, term) == -1)
    {
      printf("tsetattr\n");
      errno = E_TERMCAP;
      return (-1);
    }
  return (0);
}

struct termios		*init_termcap(char **environ)
{
  char			t_buff[2048];
  struct termios	*tsave;
  struct termios	term;

  if (environ && tgetent(t_buff, my_getenv(environ, "TERM=")) == -1)
    if (tgetent(t_buff, "xterm") == -1)
      {
	errno = E_TERMCAP;
	return (NULL);
      }
  if (tcgetattr(0, &term) == -1)
    {
      errno = E_TERMCAP;
      return (NULL);
    }
  if (!(tsave = my_memalloc(sizeof(*tsave))))
    return (NULL);
  my_memcpy(tsave, &term, sizeof(*tsave));
  term.c_lflag &= ~(ICANON);
  if (my_tcsetattr(0, TCSANOW, &term))
    return (NULL);
  term.c_lflag &= ~(ECHO);
  if (my_tcsetattr(0, TCSANOW, &term))
    return (NULL);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (my_tcsetattr(0, TCSANOW, &term))
    return (NULL);
  return (tsave);
}
