/*
** inf_add.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src/
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Nov  6 17:20:46 2014
** Last update Sun Nov  9 17:26:15 2014 Cano Chloe
*/

#include <eval_expr.h>

void		do_add(t_nb *res, t_nb *n1, t_nb *n2, t_base *s_base)
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
	+ get_base_idx(*(n2->nb + ps2), s_base->base);
      res->nb[pos] += res->nb[pos + 1] / s_base->base_len;
      res->nb[pos + 1] %= s_base->base_len;
    }
  while (ps1 >= 0 && --pos >= 0)
    {
      res->nb[pos + 1] += get_base_idx(*(n1->nb + ps1), s_base->base);
      res->nb[pos] += res->nb[pos + 1] / s_base->base_len;
      res->nb[pos + 1] %= s_base->base_len;
      --ps1;
    }
}

void		do_add_or_sub(t_nb *res, t_nb *s1, t_nb *s2, t_base *s_base)
{
  if (res->sign == 1 || res->sign == 2)
    do_sub(res, s1, s2, s_base);
  else
    do_add(res, s1, s2, s_base);
}

static void	set_ret_sign(t_nb *res, int swap)
{
  if (res->sign == 1)
    res->sign = swap ? 0 : 1;
  if (res->sign == 2)
    res->sign = swap ? 1 : 0;
  if (res->sign == 3)
    res->sign = 1;
}

t_nb		*inf_add(t_nb *n1, t_nb *n2, t_base *s_base, char *ops)
{
  t_nb		*res;
  int		swap;

  if (!(res = malloc(sizeof(*res))))
    return (NULL);
  if (ops)
    res->sign = get_sign(n1, n2, ops[3]);
  else
    res->sign = 0;
  swap = order_operands(&n1, &n2);
  if (!(res->nb = malloc(sizeof(*res) * (n1->len + 3))))
    return (NULL);
  my_bzero(res->nb, n1->len + 3 + 3);
  do_add_or_sub(res, n1, n2, s_base);
  set_ret_sign(res, swap);
  if (ops)
    res->len = clean_res(res, n1->len + 3, s_base->base, ops[3]);
  else
    res->len = clean_res(res, n1->len + 3, s_base->base, 0);
  if (!res->len)
    return (NULL);
  return (res);
}
