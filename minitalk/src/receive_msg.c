/*
** receive_msg.c for minitalk in /home/cano_c/rendu/UNIX/PSU_2014_minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Mar 16 12:33:14 2015 
** Last update Mon Mar 16 12:33:44 2015 
*/
#include <minitalk.h>

void		client_unreachable(void)
{
  g_pid = -1;
  my_putstr_fd("\033[31m [\033[0m", 2);
  my_putnbr_fd(g_pid, 2);
  my_putstr_fd("\033[31m] cannot reach client, abort\n", 2);
  signal(SIGUSR1, &sig_receive_pid);
  signal(SIGUSR2, &sig_receive_pid);
}

void	        complete_char(char *c)
{
  write(1, c, 1);
  if (*c == 0)
    {
      write(2, "\n\n", 2);
      signal(SIGUSR1, &sig_receive_pid);
      signal(SIGUSR2, &sig_receive_pid);
      if (kill(g_pid, SIGUSR2))
	client_unreachable();
      g_pid = -1;
    }
  else
    {
      *c = 0;
      if (kill(g_pid, SIGUSR1))
	client_unreachable();
    }
}

void		sig_receive_msg(int sig)
{
  static char	c = 0;
  static size_t	count = 0;

  signal(SIGUSR1, &sig_receive_msg);
  signal(SIGUSR2, &sig_receive_msg);
  c |= sig == SIGUSR1 ? 0 : 1 << count;
  if (++count == 8)
    {
      count = 0;
      complete_char(&c);
    }
  else if (kill(g_pid, SIGUSR1))
    {
      c = 0;
      count = 0;
      client_unreachable();
    }
}
