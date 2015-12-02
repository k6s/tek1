/*
** client.c for minitalk in /home/k6/epitech/UNIX/minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Feb 20 13:43:52 2015
** Last update Mon Mar 16 12:13:54 2015 
*/
#include <minitalk.h>

char		*msg;

void		sig_exit(int UN signo)
{
  exit(0);
}

int		is_num(char *arg)
{
  while (*arg)
    {
      if (*arg > '9' || *arg < '0')
	return (0);
      ++arg;
    }
  return (1);
}

int		get_pids(char *c_serv_pid, int *serv_pid)
{
  int		pid;

  if (!is_num(c_serv_pid) || (*serv_pid = my_getnbr(c_serv_pid)) < 0)
    {
      write(2, USAGE, my_strlen(USAGE));
      return (-1);
    }
  if ((pid = getpid()) < 0)
    {
      write(2, EPID, my_strlen(EPID));
      return (-1);
    }
  return (pid);
}

int		main(int argc, char **argv)
{
  int		serv_pid;
  int		pid;

  if (argc == 3)
    {
      if ((pid = get_pids(argv[1], &serv_pid)) < 0)
	return (-1);
      send_pid(pid, serv_pid);
      send_str(serv_pid, argv[2]);
      return (0);
    }
  else
    write(2, USAGE, my_strlen(USAGE));
  return (-1);
}
