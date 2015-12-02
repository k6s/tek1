/*
** printf.c for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf/src/printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 08:11:12 2014
** Last update Sun Nov 16 22:07:07 2014 
*/

#include <my.h>

void		init_va(int (*ft_get_va[256])(t_printf *, t_printf_s *))
{
  int		idx;

  idx = 0;
  while (idx < 256)
    {
      if (idx == 'h' || idx == 'i' || idx == 'l' || idx == 'L' || idx == 'j'
	  || idx == 't' || idx == 'b' || idx == 'd' || idx == 'j' || idx == 'z')
	ft_get_va[idx] = &get_ll;
      else if (idx == 'd' || idx == 'i')
	ft_get_va[idx] = &get_ll;
      else if (idx == 'o' || idx == 'u' || idx == 'x' || idx == 'X'
	       || idx == 'p')
	ft_get_va[idx] = &get_ll;
      else if (idx == 's')
	ft_get_va[idx] = &get_str;
      else if (idx == 'c')
	ft_get_va[idx] = &get_char;
      else
	ft_get_va[idx] = NULL;
      ++idx;
    }
}

void		init_ft_cast(char (*ft_cast[256])(t_types *, char len[2]))
{
  ft_cast['h'] = &cast_char_short;
  ft_cast['l'] = &cast_long_llong;
  ft_cast['z'] = &cast_ssize_t;
  ft_cast['t'] = &cast_ptrdiff_t;
  ft_cast['i'] = &cast_int;
  ft_cast['d'] = &cast_int;
  ft_cast['u'] = &cast_long_llong;
  ft_cast['o'] = &cast_long_llong;
  ft_cast['x'] = &cast_long_llong;
  ft_cast['X'] = &cast_long_llong;
  ft_cast['p'] = &cast_addr;
  ft_cast['b'] = &cast_int;
  ft_cast['j'] = &cast_intmax_t;
}

int		my_printf(char *str, ...)
{
  t_printf	s_printf;
  t_printf_s	s_printf_s;
  int		ret;

  va_start(s_printf.ap, str);
  s_printf_s.str = str;
  init_ft_cast(s_printf.ft_cast);
  init_va(s_printf.ft_get_va);
  ret = parse_str(&s_printf, &s_printf_s);
  va_end(s_printf.ap);
  return (ret);
}
