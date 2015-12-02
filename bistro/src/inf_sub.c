/*
** inf_sub.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src/
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Nov  6 17:20:46 2014
** Last update Sun Nov  9 17:26:43 2014 Cano Chloe
*/

#include <eval_expr.h>

void		handle_ret(t_nb *res, int pos, t_base *s_base)
{
  if (res->nb[pos + 1] < 0)
    {
      res->nb[pos + 1] += s_base->base_len;
      --res->nb[pos];
    }
}

void		do_sub(t_nb *res, t_nb *n1, t_nb *n2, t_base *s_base)
{
  int		ps1;
  int		ps2;
  int		pos;

  pos = n1->len + 2;
  ps1 = n1->len;
  ps2 = n2->len;
  while (--ps1 >= 0 && --ps2 >= 0)
    {
      --pos;
      res->nb[pos + 1] += get_base_idx(*(n1->nb + ps1), s_base->base)
	- get_base_idx(*(n2->nb + ps2), s_base->base);
      handle_ret(res, pos, s_base);
      res->nb[pos] += res->nb[pos + 1] / s_base->base_len;
      res->nb[pos + 1] %= s_base->base_len;
    }
  while (ps1 >= 0 && --pos >= 0)
    {
      res->nb[pos + 1] += get_base_idx(*(n1->nb + ps1), s_base->base);
      handle_ret(res, pos, s_base);
      res->nb[pos] += res->nb[pos + 1] / s_base->base_len;
      res->nb[pos + 1] %= s_base->base_len;
      --ps1;
    }
}

void		do_sub_or_add(t_nb *s1, t_nb *s2, t_nb *res, t_base *s_base)
{
  if (res->sign == 1 || res->sign == 2)
    do_add(res, s1, s2, s_base);
  else
    do_sub(res, s1, s2, s_base);
}

t_nb		*inf_sub(t_nb *n1, t_nb *n2, t_base *s_base, char *ops)
{
  t_nb		*res;
  int		sign;

  if (!(res = malloc(sizeof(*res))))
    return (NULL);
  if (ops)
    res->sign = get_sign(n1, n2, ops[3]);
  else
    res->sign = 0;
  sign = order_operands(&n1, &n2);
  if (!(res->nb = malloc(sizeof(*res) * (n1->len + 3))))
    return (NULL);
  my_bzero(res->nb, n1->len + 3 + 3);
  do_sub_or_add(n1, n2, res, s_base);
  res->sign = (!res->sign && sign)
    || (!sign && res->sign == 3) ? 1 : res->sign;
  res->sign = res->sign == 1 ? 1 : res->sign;
  res->sign = res->sign == 2 ? 0 : res->sign;
  res->sign = res->sign == 3 && sign ? 0 : res->sign;
  if (ops)
    res->len = clean_res(res, n1->len + 3, s_base->base, ops[3]);
  else
    res->len = clean_res(res, n1->len + 3, s_base->base, 0);
  return (res);
}
