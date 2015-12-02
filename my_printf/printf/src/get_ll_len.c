/*
** printf.c for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Nov 11 04:50:56 2014
** Last update Sun Nov 16 22:22:39 2014 
*/

#include <my.h>
#include <limits.h>

static int	get_unsigned(unsigned long long var, int base_len)
{
  int		ret;

  ret = 0;
  if (var >= (unsigned)base_len)
    ret += get_unsigned(var / base_len, base_len);
  return (ret + 1);
}

static int	get_signed(signed long long var, int base_len)
{
  int		ret;

  ret = 0;
  if (var < 0)
    {
      if (var == LLONG_MIN)
	{
	  get_signed(var / base_len, base_len);
	  get_signed(var % base_len * -1, base_len);
	}
      else
	{
	  ++ret;
	  var *= -1;
	}
    }
  if (var >= base_len)
    ret += get_signed(var / base_len, base_len);
  return (ret + 1);
}

int		get_ll_len(t_types *var, char conv, unsigned int base_len)
{
  if (conv == 'i' || conv == 'd' || conv == 'j' || conv == 't' || conv == 'z')
    {
      var->lls = (signed long long)var->lls;
      return (get_signed(var->lls, base_len));
    }
  else if (conv == 'u' || conv == 'o' || conv == 'X' || conv == 'x'
	   || conv == 'p')
    return (get_unsigned(var->llu, base_len));
  return (-1);
}
