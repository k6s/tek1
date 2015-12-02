/*
** send_pid.c for minitalk in /home/cano_c/rendu/UNIX/PSU_2014_minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Mar 12 17:46:31 2015 
** Last update Thu Mar 12 17:46:54 2015 
*/
#include <minitalk.h>

void		send_pid(int pid, int serv_pid)
{
  size_t       	count;
  char		*s_pid;

  s_pid = (char *)(&pid);
  count = 0;
  while (count < PID_BLEN)
    {
      if (kill(serv_pid, (s_pid[count / 8] >> (count % 8)) & 1
	       ? SIGUSR2 : SIGUSR1))
	server_unreachable();
      ++count;
      usleep(1000);
    }
}
