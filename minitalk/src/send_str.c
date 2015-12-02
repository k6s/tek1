/*
** send_str.c for minitalk.h in /home/cano_c/rendu/UNIX/PSU_2014_minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Mar 12 17:44:43 2015
** Last update Mon Mar 16 12:15:39 2015 
*/
#include <minitalk.h>

void		sig_send_bit(int signo)
{
  static int	idx = 1;

  signal(SIGUSR1, &sig_send_bit);
  signal(SIGUSR2, &sig_exit);
  signo = (*msg >> idx) & 1 ? SIGUSR2 : SIGUSR1;
  if (++idx == 8)
    {
      ++msg;
      idx = 0;
    }
  kill_serv(signo, -1);
}

int		send_str(int pid, char *str)
{
  const char	empty[2] = {"1"};
  int		signo;

  msg = *str ? str : (char *)(empty + 1);
  signal(SIGUSR1, &sig_send_bit);
  signal(SIGUSR2, &sig_exit);
  signo = *msg & 1 ? SIGUSR2 : SIGUSR1;
  kill_serv(signo, pid);
  while ((*msg || *(msg - 1)))
    pause();
  return (1);
}
