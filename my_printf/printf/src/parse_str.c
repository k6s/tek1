/*
** parse_str.c for printf in ~/rendu/UNIX/PSU_2014_my_printf/src/printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 08:07:22 2014
** Last update Sun Nov 16 20:23:22 2014 Cano Chloe
*/
#include <my.h>

static int	parse_percent(t_printf *s_printf, t_printf_s *s_str)
{
  int		ret;

  ret = 0;
  while (*s_str->str && *s_str->str == '%'
	 && *(s_str->str + 1) == '%')
    {
      my_putchar('%');
      ++ret;
      s_str->str += 2;
    }
  if (*s_str->str == '%')
    {
      ++s_str->str;
      ret += output_va(s_printf, s_str);
    }
  return (ret);
}

int		parse_str(t_printf *s_printf, t_printf_s *s_str)
{
  int		ret;

  ret = 0;
  while (*s_str->str)
    {
      while (*s_str->str && *s_str->str != '%')
	{
	  my_putchar(*s_str->str);
	  ++s_str->str;
	  ++ret;
	}
      ret += parse_percent(s_printf, s_str);
    }
  return (ret);
}
