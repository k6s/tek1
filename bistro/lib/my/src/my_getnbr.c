/*
** my_getnbr.c for my_getnbr.c in /home/k6/rendu/Piscine_C_J04
** 
** Made by Cano Chloe
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Oct  3 09:21:15 2014 Cano Chloe
** Last update Sun Nov  9 13:19:50 2014 
*/

#include <my.h>

int			my_getnbr(char *str)
{
  int		res;
  char		sign;

  res = 0;
  sign = 1;
  while (*str == '+' || *str == '-')
    {
      if (*str == '-')
	sign *= -1;
      ++str;
    }
  while (*str && (*str >= '0' && *str <= '9'))
    {
      res *= 10;
      res += *str - '0';
      ++str;
      if (res < 0 && !((res == INT_MIN) && (sign == -1)))
	return (0);
    }
  if (res != INT_MIN && sign == -1)
    res *= (int)sign;
  return (res);
}
