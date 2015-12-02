/*
** my_put_nbr.c for my_put_nbr.c in /home/k6/rendu/test
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Thu Oct  2 17:06:43 2014 Cano Chloe
** Last update Thu Mar 12 13:52:51 2015 
*/

#include <my.h>

int			my_putnbr_fd(int n, int fd)
{
  char			c;

  if (n == INT_MIN)
    {
      my_putnbr_fd(INT_MIN / 10, fd);
      my_putnbr_fd(INT_MIN % 10 * -1, fd);
      return (0);
    }
  if (n < 0)
    {
      write(fd, "-", 1);
      n *= -1;
    }
  if (n >= 10)
    my_putnbr_fd(n / 10, fd);
  c = n % 10 + '0';
  write(fd, &c, 1);
  return (0);
}
