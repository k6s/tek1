/*
** inf_mod.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 01:09:41 2014
** Last update Sun Nov  9 17:02:17 2014 Cano Chloe
*/

#include <eval_expr.h>

t_nb		*do_mod(t_nb *n1, t_nb *n2, t_base *s_base)
{
  t_nb		*tmp;
  t_nb		*to_free;
  int		cmp;
  t_nb		*res;

  if (!(tmp = mk_zero(s_base->base[0])))
    return (NULL);
  cmp = 0;
  while (n1->len > tmp->len
	 || (tmp->len == n1->len
	     && (cmp = my_memcmp(tmp->nb, n1->nb, n1->len)) < 0))
    {
      to_free = tmp;
      if (!(tmp = inf_add(tmp, n2, s_base, 0)))
	return (NULL);
      free(to_free->nb);
      free(to_free);
    }
  if (n1->len < tmp->len || cmp > 0)
    tmp = inf_sub(tmp, n2, s_base, NULL);
  if (!(res = inf_sub(n1, tmp, s_base, NULL)))
    return (NULL);
  free(tmp->nb);
  free(tmp);
  return (res);
}

static void	set_ret_sign(t_nb *res)
{
  if (res->sign == 1)
    res->sign = 1;
  else
    res->sign = 0;
}

t_nb		*inf_mod(t_nb *n1, t_nb *n2, t_base *s_base, char *ops)
{
  t_nb		*res;
  int		sign;

  if (zero_check(n2, s_base->base[0], ops[3], ops[2]))
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (NULL);
    }
  sign = get_sign(n1, n2, ops[3]);
  if (!(res = do_mod(n1, n2, s_base)))
    return (NULL);
  res->sign = sign;
  set_ret_sign(res);
  if (res->sign && !zero_check(res, s_base->base[0], ops[3], ops[2]))
    {
      my_memmove(res->nb + 1, res->nb, res->len);
      *res->nb = ops[3];
      ++res->len;
    }
  return (res);
}
