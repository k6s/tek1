/*
** zero.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 02:33:56 2014
** Last update Sun Nov  9 17:28:10 2014 Cano Chloe
*/
#include <eval_expr.h>

char		zero_check(t_nb *s_nb, char zero, char min, char plus)
{
  int		is_zero;
  int		i;

  is_zero = 1;
  i = -1;
  while ((unsigned)++i < s_nb->len && is_zero)
    {
      if (s_nb->nb[i] != zero && s_nb->nb[i] != min && s_nb->nb[i] != plus)
	is_zero = 0;
    }
  return (is_zero);
}

t_nb		*mk_zero(char zero)
{
  t_nb		*s_zero;

  if (!(s_zero = malloc(sizeof(*s_zero))))
    return (NULL);
  if (!(s_zero->nb = malloc(sizeof(*s_zero->nb))))
    return (NULL);
  *s_zero->nb = zero;
  s_zero->len = 1;
  return (s_zero);
}
