/*
** kill_serv.c for minitalk.h in /home/cano_c/rendu/UNIX/PSU_2014_minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Mar 16 12:21:44 2015 
** Last update Mon Mar 16 12:24:22 2015 
*/
#include <minitalk.h>

int		server_unreachable(void)
{
  write(2, "minitalk: Cannot reach server, exiting...\n", 42);
  exit(EXIT_FAILURE);
}

void		kill_serv(int signo, int new_pid)
{
  static int	pid = -1;

  if (new_pid > -1)
    pid = new_pid;
  if (kill(pid, signo))
    server_unreachable();
}
