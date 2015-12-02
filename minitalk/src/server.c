/*
** server.c for minitalk in /home/k6/epitech/UNIX/minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Feb 20 13:39:12 2015
** Last update Mon Mar 16 12:30:21 2015 
*/
#include <minitalk.h>

int		g_pid = 0;

int			main(void)
{
  my_putstr_fd("Minitalk server up and running with pid: ", 2);
  my_put_nbr(getpid());
  write(2, "\n\n", 2);
  while (1)
    {
      new_client();
      pause();
    }
  return (0);
}
