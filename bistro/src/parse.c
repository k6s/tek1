/*
** parse.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 12:47:24 2014
** Last update Sun Nov  9 17:02:32 2014 Cano Chloe
*/

#include <eval_expr.h>

char		p_end(t_bistro *bistro, t_expr **stack, char UN *ctt)
{
  if (bistro->par != 0)
    return (p_e(bistro, stack, ctt));
  stack_to_expr(stack, bistro->s_expr);
  return (TYPE_END);
}

char		p_sign(t_bistro *bistro, t_expr **stack, char UN *ctt)
{
  char		sign;
  t_nb		*s_nb;

  sign = 1;
  while (((*bistro->str == bistro->ops[3] || *bistro->str == bistro->ops[2])
	  && ctt[(int)*(bistro->str + 1)] != DIV)
	 || ((bistro->trail_spc < 0 && *bistro->str == ' ')
	     || *bistro->str == '\t'))
    {
      if (*bistro->str == bistro->ops[3])
	sign *= -1;
      ++bistro->str;
    }
  if (sign < 0)
    {
      if (!(s_nb = malloc(sizeof(*s_nb))))
	return (TYPE_ERR);
      s_nb->len = 1;
      if (!(s_nb->nb = malloc(sizeof(*s_nb->nb))))
	return (TYPE_ERR);
      *s_nb->nb = bistro->base[0];
      to_expr(&bistro->s_expr, s_nb, NUM);
      push(stack, bistro->ops[3], NULL, SIGN);
    }
  return (TYPE_SIGN);
}

char		p_op(t_bistro *bistro, t_expr UN **stack, char *ctt)
{
  t_expr	*curr;
  t_expr	*tmp;
  char		type;

  tmp = bistro->s_expr;
  while (tmp->next)
    tmp = tmp->next;
  curr = *stack;
  type = ctt[(int)*(bistro->str)];
  while (curr && type >= curr->type && curr->elem != bistro->ops[0])
    {
      tmp->next = pop(stack);
      if (tmp->next->type == PARB || tmp->next->type == PARE)
	return (p_e(bistro, stack, ctt));
      tmp->next->prev = tmp;
      curr = *stack;
      tmp = tmp->next;
    }
  push(stack, *bistro->str, NULL, type);
  ++(bistro->str);
  return (TYPE_OP);
}

char		p_nb(t_bistro *bistro, t_expr UN **stack, char UN *ctt)
{
  t_nb		*s_nb;

  if (!(s_nb = malloc(sizeof(*s_nb))))
    return (TYPE_ERR);
  s_nb->len = 0;
  while (get_base_idx(*(bistro->str + s_nb->len), bistro->base) > -1)
    ++s_nb->len;
  if (!(s_nb->nb = malloc(sizeof(*s_nb->nb) * (s_nb->len))))
    return (TYPE_ERR);
  my_memcpy(s_nb->nb, bistro->str, s_nb->len);
  bistro->str += s_nb->len;
  to_expr(&bistro->s_expr, s_nb, NUM);
  return (TYPE_NB);
}

char		p_e(t_bistro *bistro, UN t_expr **stack, UN char *ctt)
{
  t_expr	*tmp;

  while (bistro->s_expr)
    {
      tmp = bistro->s_expr;
      bistro->s_expr = bistro->s_expr->next;
      free(tmp);
    }
  my_putstr(SYNTAXE_ERROR_MSG);
  return (TYPE_ERR);
}
