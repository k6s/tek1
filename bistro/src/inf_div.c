/*
** inf_div.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 01:09:41 2014
** Last update Sun Nov  9 17:02:01 2014 Cano Chloe
*/
#include <eval_expr.h>

char		do_div(t_nb *res, t_nb *n1, t_nb *n2, t_base *s_base)
{
  t_nb		*tmp;
  t_nb		*to_free;
  int		cmp;

  if (!(tmp = mk_zero(s_base->base[0])))
    return (-1);
  cmp = 0;
  while (n1->len > tmp->len
	 || (tmp->len == n1->len
	     && (cmp = my_memcmp(tmp->nb, n1->nb, n1->len)) < 0))
    {
      add_one(res, n1->len, s_base->base_len);
      to_free = tmp;
      if (!(tmp = inf_add(tmp, n2, s_base, 0)))
	return (-1);
      free(to_free->nb);
      free(to_free);
    }
  if (n1->len < tmp->len || cmp > 0)
    sub_one(res, n1->len, s_base->base_len);
  free(tmp->nb);
  free(tmp);
  return (0);
}

static void	set_ret_sign(t_nb *res)
{
  if (res->sign == 1 || res->sign == 2)
    res->sign = 1;
  else
    res->sign = 0;
}

t_nb		*inf_div(t_nb *n1, t_nb *n2, t_base *s_base, char *ops)
{
  t_nb		*res;

  if (zero_check(n2, s_base->base[0], ops[3], ops[2]))
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (NULL);
    }
  if (!(res = malloc(sizeof(*res))))
    return (NULL);
  res->sign = get_sign(n1, n2, ops[3]);
  if (!(res->nb = malloc(sizeof(*res) * (n1->len + 2))))
    return (NULL);
  my_bzero(res->nb, n1->len + 2);
  if (do_div(res, n1, n2, s_base) < 0)
    return (NULL);
  set_ret_sign(res);
  if (!(res->len = clean_res(res, n1->len + 2, s_base->base, ops[3])))
    return (NULL);
  return (res);
}
