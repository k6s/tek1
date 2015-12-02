/*
** new_client.c for minitalk in /home/cano_c/rendu/UNIX/PSU_2014_minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Mar 16 12:26:56 2015
** Last update Mon Mar 16 12:27:05 2015 
*/
#include <minitalk.h>

void		client_accepted(void)
{
  signal(SIGUSR1, &sig_receive_msg);
  signal(SIGUSR2, &sig_receive_msg);
  my_putstr_fd(" \033[32m[\033[0m", 2);
  my_put_nbr(g_pid);
  my_putstr_fd("\033[32m] client accepted\033[0m\n\n", 2);
}

void		client_refused(void)
{
  g_pid = -1;
  signal(SIGUSR1, &sig_receive_pid);
  signal(SIGUSR2, &sig_receive_pid);
  my_putstr_fd(" \033[31m[\033[0m", 2);
  my_putnbr_fd(g_pid, 2);
  my_putstr_fd("\033[31m] client refused\033[0m\n\n", 2);
}

void		sig_receive_pid(int sig)
{
  static size_t	count = 0;
  char		*s_pid;

  signal(SIGUSR1, &sig_receive_pid);
  signal(SIGUSR2, &sig_receive_pid);
  if (!count)
    g_pid = 0;
  s_pid = (char *)(&g_pid);
  s_pid[count / 8] |= sig == SIGUSR1 ? 0 : 1 << count % 8;
  if (++count == PID_BLEN)
    {
      count = 0;
      if (g_pid > -1)
	client_accepted();
      else
	client_refused();
    }
}

void			new_client(void)
{
  signal(SIGUSR1, &sig_receive_pid);
  signal(SIGUSR2, &sig_receive_pid);
  while (g_pid != -1)
    pause();
}
