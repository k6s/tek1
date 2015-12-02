/*
1;2802;0c** print_va.c for printf in ~/rendu/UNIX/PSU_2014_my_printf/src/printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 08:22:04 2014
** Last update Sun Nov 16 22:23:31 2014 
*/

#include <my.h>

int		undefined_conv(t_printf_s *s_str, char idx)
{
  --s_str->str;
  my_putchar('%');
  return (1);
}

int		get_ftptr_idx(t_printf *s_printf, t_printf_s *s_str)
{
  int		idx;

  if (!(get_flags(s_printf, s_str)))
    get_width(s_str);
  if (get_len(s_str))
    {
      s_str->conv = *s_str->str++;
      idx = *s_str->len;
    }
  else
    {
      s_str->conv = *s_str->str++;
      idx = s_str->conv;
    }
  if (!((void *)(s_printf->ft_get_va[idx])))
    idx = -1;
  return (idx);
}

int     	output_va(t_printf *s_printf, t_printf_s *s_str)
{
  int		idx;

  if ((idx = get_ftptr_idx(s_printf, s_str)) < 0)
    return (undefined_conv(s_str, idx));
  (*s_printf->ft_get_va[idx])(s_printf, s_str);
  if (s_str->conv == 'i' || s_str->conv == 'd' || s_str->conv == 'u')
    return (output_integer(s_str, 10));
  if (s_str->conv == 'x' || s_str->conv == 'X' || s_str->conv == 'p')
    return (output_integer(s_str, 16));
  if (s_str->conv == 'o')
    return (output_integer(s_str, 8));
  if (s_str->conv == 'b')
    return (output_integer(s_str, 2));
  if (s_str->conv == 'c')
    return (output_char(s_str));
  if (s_str->conv == 's')
    return (output_str(s_str));
  return (-1);
}
