/*
** print_str.c for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Nov 15 16:27:10 2014
** Last update Sun Nov 16 21:15:54 2014 
*/

#include <my.h>

int		output_str(t_printf_s *s_str)
{
  int		ret;
  int		nb_len;
  int		idx;

  ret = 0;
  idx = -1;
  if (s_str->var.str)
    nb_len = my_strlen(s_str->var.str);
  else
    nb_len = 0;
  if (s_str->width > -1)
    ret = spc_padding(nb_len, s_str->width, ' ');
  if (s_str->var.str)
    {
      if (s_str->prec < 0 || s_str->prec > nb_len)
	ret += my_putstr(s_str->var.str);
      else
	while (++idx < s_str->prec && s_str->var.str[idx])
	  my_putchar(s_str->var.str[idx]);
    }
  else
    ret += my_putstr("(null)");
  if (s_str->width < -1 && s_str->fill == ' ')
    ret += spc_padding(nb_len, s_str->width * -1, s_str->fill);
  return (ret);
}
