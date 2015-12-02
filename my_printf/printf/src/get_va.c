/*
** get_va.c for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf/printf/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 10:24:25 2014
** Last update Sun Nov 16 22:12:51 2014 
*/

#include <my.h>

int		get_ll(t_printf *s_printf, t_printf_s *s_str)
{
  s_str->var.lls = va_arg(s_printf->ap, signed long long int);
  if (*s_str->len)
    s_str->neg = (*s_printf->ft_cast[(int)*s_str->len])
      (&s_str->var, s_str->len);
  else
    s_str->neg = (*s_printf->ft_cast[(int)s_str->conv])
      (&s_str->var, s_str->len);
  return (-1);
}

int		get_str(t_printf *s_printf, t_printf_s *s_str)
{
  s_str->var.str = (char *)va_arg(s_printf->ap, const char *);
  if (*s_str->len)
    s_str->neg = (*s_printf->ft_cast[(int)*s_str->len])
      (&s_str->var, s_str->len);
  return (-1);
}

int		output_char(t_printf_s *s_str)
{
  int		len;
  int		ret;

  ret = 0;
  len = 1;
  if (s_str->width >= 0 && s_str->width != '-')
    ret += spc_padding(len, s_str->width, ' ');
  my_putchar(s_str->var.c);
  if (s_str->width < -1)
    ret += spc_padding(len, s_str->width * -1, ' ');
  return (ret + 1);
}

int		get_char(t_printf *s_printf, t_printf_s *s_str)
{
  int		ret;

  ret = 0;
  s_str->var.c = (char)va_arg(s_printf->ap, int);
  if (*s_str->len)
    s_str->neg = (*s_printf->ft_cast[(int)*s_str->len])
      (&s_str->var, s_str->len);
  return (ret);
}

int		get_ldouble(t_printf *s_printf, t_printf_s *s_str)
{
  s_str->var.ldouble = va_arg(s_printf->ap, long double);
  if (*s_str->len)
    s_str->neg = (*s_printf->ft_cast[(int)*s_str->len])
      (&s_str->var, s_str->len);
  return (-1);
}
