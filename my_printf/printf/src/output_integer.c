/*
1;2802;0c1;2802;0c** output_nb.c for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov 16 19:48:25 2014
** Last update Sun Nov 16 22:27:12 2014 
*/

#include <my.h>

static char	get_prefix(char before, signed long long *lls, char conv,
			   char neg)
{
  if ((conv == 'i' || conv == 'd') && neg)
    {
      if (*lls != LLONG_MIN)
	*lls *= -1;
      return ('-');
    }
  else
    {
      if (before & F_PLS)
	return ('+');
      if (before & F_SPC)
	return (' ');
    }
  return (-1);
}

int		handle_diez(t_printf_s *s_str, int *prefix_len, ssize_t *nb_len,
			    char *diez_prefix)
{
  int		ret;

  ret = 0;
  diez_prefix[0] = 0;
  diez_prefix[1] = 0;
  diez_prefix[2] = 0;
  if (s_str->conv == 'o' && s_str->var.lls && ++(*prefix_len))
    {
      ++(*nb_len);
      diez_prefix[0] = '0';
      ++ret;
    }
  else if (s_str->conv == 'x' && (*prefix_len += 2))
    {
      *nb_len += 2;
      diez_prefix[0] = '0';
      diez_prefix[1] = 'x';
      ret += 2;
    }
  else if (s_str->conv == 'X' && (*prefix_len += 2))
    {
      *nb_len += 2;
      diez_prefix[0] = '0';
      diez_prefix[1] = 'X';
      ret += 2;
    }
  return (ret);
}

int		get_nblen_prefix(t_printf_s *s_str, char *prefix,
				 ssize_t *nb_len, size_t base_len)
{
  int		prefix_len;

  *prefix = get_prefix(s_str->before, &s_str->var.lls, s_str->conv,
			s_str->neg);
  prefix_len = 0;
  if (s_str->conv != 'i' && s_str->conv != 'd' && s_str->conv != 'p')
    {
      if ((*prefix == '+') || (*prefix == ' ') || !(*prefix))
	*prefix = -1;
    }
  *nb_len = (ssize_t)get_ll_len(&s_str->var, s_str->conv, base_len);
  if (*prefix != -1)
    {
      ++(*nb_len);
      ++prefix_len;
    }
  if (s_str->conv == 'p')
    *nb_len += 2;
  if (s_str->prec > 0)
    *nb_len += s_str->prec;
  return (prefix_len);
}

int		output_integer_prefix(t_printf_s *s_str, ssize_t *nb_len,
				      int base_len)
{
  int		ret;
  char		prefix;
  int		prefix_len;
  char		diez_prefix[3] = {0};

  ret = 0;
  prefix_len = get_nblen_prefix(s_str, &prefix, nb_len, base_len);
  if (s_str->before & F_DIZ)
    ret += handle_diez(s_str, &prefix_len, nb_len, (char *)diez_prefix);
  if (s_str->width >= 0 && s_str->fill == ' ')
    ret += spc_padding(*nb_len, s_str->width, s_str->fill);
  if (prefix > -1)
    {
      my_putchar(prefix);
      ++ret;
    }
  my_putstr(diez_prefix);
  if (s_str->conv == 'p' && (ret += 2))
    my_putstr("0x");
  if (s_str->prec > 0)
    ret += spc_padding(*nb_len - s_str->prec, s_str->prec + prefix_len, '0');
  if (s_str->width >= 0 && s_str->fill == '0')
    ret += spc_padding(*nb_len, s_str->width, s_str->fill);
  return (ret);
}

int		output_integer(t_printf_s *s_str, int base_len)
{
  ssize_t	nb_len;
  int		ret;

  ret = output_integer_prefix(s_str, &nb_len, base_len);
  if (base_len == 10 || base_len == 8)
    ret += put_ll_reg(&s_str->var, s_str->conv, base_len);
  else
    {
      if (s_str->conv == 'x' || s_str->conv == 'p')
	ret += put_ll_base(&s_str->var, "0123456789abcdef", base_len);
      else if (s_str->conv == 'X')
	ret += put_ll_base(&s_str->var, "0123456789ABCDEF", base_len);
      else if (s_str->conv == 'b')
	ret += put_ll_base(&s_str->var, "01", base_len);
    }
  if (s_str->width < -1 && s_str->fill == ' ')
    ret += spc_padding(nb_len, s_str->width * -1, s_str->fill);
  return (ret);
}
