/*
** parse_flags.c for printf in ~/rendu/UNIX/PSU_2014_my_printf/src/printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 08:00:15 2014
** Last update Sun Nov 16 21:12:39 2014 
*/

#include <my.h>

void			init_flags(t_printf_s *s_str, int *ret)
{
  s_str->before = 0;
  s_str->fill = ' ';
  s_str->width = -1;
  s_str->prec = -1;
  *ret = 0;
}

void			parse_star_prec(t_printf *s_printf, t_printf_s *s_str,
					int *ret)
{
  if (*s_str->str == '*')
    {
      s_str->var.lls = va_arg(s_printf->ap, int);
      if (*(s_str->str - 1) == '.')
	s_str->prec = s_str->var.lls;
      else
	{
	  s_str->width = s_str->width == '-' ?
	    -1 * s_str->var.lls : s_str->var.lls;
	  *ret = 1;
	}
    }
  else if (*s_str->str == '.' && *(s_str->str + 1) != '*')
    {
      s_str->prec = my_getnbr(s_str->str + 1);
      while (*(s_str->str + 1) == '-' || *(s_str->str + 1) == '+')
	++s_str->str;
      while (*(s_str->str + 1) <= '9' && *(s_str->str + 1) >= '0')
	++s_str->str;
    }
}

char			get_flags(t_printf *s_printf, t_printf_s *s_str)
{
  int			ret;

  init_flags(s_str, &ret);
  while (*s_str->str == '#' || *s_str->str == '0' || *s_str->str == '-'
	 || *s_str->str == '+' || *s_str->str == ' ' || *s_str->str == '\''
	 || *s_str->str == '*' || *s_str->str == '.')
    {
      if (*s_str->str == '-')
	{
	  s_str->fill = ' ';
	  s_str->width = '-';
	}
      else if (*s_str->str == '0' && s_str->width != '-')
	s_str->fill = '0';
      else if (*s_str->str == '.' || *s_str->str == '*')
	parse_star_prec(s_printf, s_str, &ret);
      else if (*s_str->str == ' ' && s_str->before != '+')
	s_str->before |= F_SPC;
      else if (*s_str->str == '+')
	s_str->before |= F_PLS;
      else if (*s_str->str == '#')
	s_str->before |= F_DIZ;
      ++s_str->str;
    }
  return (ret);
}

void			get_width(t_printf_s *s_printf)
{
  char			min;

  min = s_printf->width;
  if ((*s_printf->str >= '0' && *s_printf->str <= '9')
      || *s_printf->str == '-')
    {
      s_printf->width = my_getnbr(s_printf->str);
      if (min == '-')
	s_printf->width *= -1;
      if (*s_printf->str == '-')
	{
	  s_printf->fill = ' ';
	  ++s_printf->str;
	}
      while (*s_printf->str <= '9' && *s_printf->str >= '0')
	++s_printf->str;
    }
  else
    s_printf->width = -1;
}

char			get_len(t_printf_s *s_str)
{
  int			format_len;

  format_len = 0;
  s_str->len[0] = 0;
  if (*s_str->str == 'h' || *s_str->str == 'l' || *s_str->str == 'L'
      || *s_str->str == 'j' || *s_str->str == 'z' || *s_str->str == 't')
    {
      ++format_len;
      s_str->len[0] = *s_str->str;
      if (*(s_str->str + 1) == 'h' && ++format_len)
	s_str->len[1] = 'h';
      else if (*(s_str->str + 1) == 'l' && ++format_len)
	s_str->len[1] = 'l';
    }
  s_str->str += format_len;
  return (format_len);
}
