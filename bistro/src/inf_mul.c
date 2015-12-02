/*
** inf_mul.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src/
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Nov  6 17:20:46 2014
** Last update Sun Nov  9 17:26:34 2014 Cano Chloe
*/

#include <eval_expr.h>

void		do_mul(t_nb *res, t_nb *n1, t_nb *n2, t_base *s_base)
{
  int		ps1;
  int		ps2;

  ps1 = n1->len;
  while (--ps1 >= 0)
    {
      ps2 = n2->len;
      while (--ps2 >= 0)
	{
	  res->nb[ps1 + ps2 + 1] += get_base_idx(*(n1->nb + ps1), s_base->base)
	    * get_base_idx(*(n2->nb + ps2), s_base->base);
	  res->nb[ps1 + ps2] += res->nb[ps1 + ps2 + 1] / s_base->base_len;
	  res->nb[ps1 + ps2 + 1] %= s_base->base_len;
	}
    }
}

static void	set_ret_sign(t_nb *res)
{
  if (res->sign == 1 || res->sign == 2)
    res->sign = 1;
  else
    res->sign = 0;
}

t_nb		*inf_mul(t_nb *n1, t_nb *n2, t_base *s_base, char *ops)
{
  t_nb		*res;

  if (!(res = malloc(sizeof(*res))))
    return (NULL);
  res->sign = get_sign(n1, n2, ops[3]);
  if (!(res->nb = malloc(sizeof(*res) * (n1->len + n2->len + 1))))
    return (NULL);
  my_bzero(res->nb, n1->len + n2->len + 1);
  do_mul(res, n1, n2, s_base);
  set_ret_sign(res);
  if (!(res->len = clean_res(res, n1->len + n2->len, s_base->base, ops[3])))
    return (NULL);
  return (res);
}
