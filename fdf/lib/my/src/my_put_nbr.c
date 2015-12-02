/*
** my_put_nbr.c for my_put_nbr.c in /home/k6/rendu/test
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Thu Oct  2 17:06:43 2014 Cano Chloe
** Last update Wed Nov 19 16:49:54 2014 
*/

#include <my.h>

int			my_put_nbr(int n)
{
  int			ret;

  ret = 0;
  if (n == INT_MIN)
    {
      ret += my_put_nbr(INT_MIN / 10);
      ret += my_put_nbr(INT_MIN % 10 * -1);
      return (0);
    }
  if (n < 0)
    {
      my_putchar('-');
      n *= -1;
      ++ret;
    }
  if (n >= 10)
    ret += my_put_nbr(n / 10);
  my_putchar(n % 10 + '0');
  return (ret + 1);
}
