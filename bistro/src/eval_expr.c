/*
** eval_expr.c for eval_expr in /home/cano_c/rendu/Piscine_C_eval_expr
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Oct 24 09:12:55 2014
** Last update Sun Nov  9 17:25:10 2014 Cano Chloe
*/

#include <eval_expr.h>

void		init(t_bistro *bistro, char *str, int len[2], char **type)
{
  bistro->base_len = len[0];
  bistro->str_len = len[1];
  bistro->s_expr = NULL;
  bistro->str = str;
  type[0] = TYPE_INIT;
  bistro->par = 0;
  bistro->trail_spc = get_base_idx(' ', bistro->base);
  if (bistro->trail_spc < 0)
    bistro->trail_spc = is_op(' ', bistro->ops);
}

t_expr		*get_expr_lst(char *str, char *base, char *ops, int len[2])
{
  char		*tok;
  char		type[2];
  t_pft		**pft_mtx;
  t_bistro	bistro;
  t_expr	*stack;

  tok = get_tok(base, ops);
  bistro.base = base;
  bistro.ops = ops;
  stack = NULL;
  pft_mtx = parse_mtx();
  init(&bistro, str, len, (char **)type);
  while (type[0] != TYPE_END && type[0] != TYPE_ERR)
    {
      while (bistro.str - str < bistro.str_len
	     && (*bistro.str == '\t'
		 || (bistro.trail_spc < 0 && *bistro.str == ' ')))
      	++bistro.str;
      type[1] = tok[(int)*bistro.str];
      if (bistro.str - str == bistro.str_len)
	type[1] = END;
      type[0] = (pft_mtx[(int)type[0]][(int)type[1]])(&bistro, &stack, tok);
    }
  free_tabs(pft_mtx, tok);
  return (bistro.s_expr);
}

t_nb		*call_do_op(t_expr **stack, t_expr *s_expr, t_op *s_op,
			    char *ops)
{
  t_expr	*tmp;
  t_nb		*ret;

  tmp = pop(stack);
  s_op->n2 = tmp->nb;
  free(tmp);
  tmp = pop(stack);
  s_op->n1 = tmp->nb;
  free(tmp);
  s_op->op = s_expr->elem;
  ret = do_op(s_op, ops);
  free(s_op->n1);
  free(s_op->n2);
  return (ret);
}

t_nb		*calc_expr(t_expr *s_expr, char *ops, char *base, int base_len)
{
  t_expr	*stack;
  t_op		s_op;
  t_nb		*res;

  stack = NULL;
  s_op.base = base;
  s_op.base_len = base_len;
  while (s_expr)
    {
      if (s_expr->type == NUM)
	push(&stack, 0, s_expr->nb, NUM);
      else if (s_expr->type != NUM)
	{
	  if (!(res = call_do_op(&stack, s_expr, &s_op, ops)))
	    return (NULL);
	  push(&stack, 0, res, NUM);
	}
      s_expr = s_expr->next;
    }
  return (stack->nb);
}

t_nb		*evalexpr(char *str, char *base, char *ops, int len[2])
{
  t_expr	*s_expr;
  t_nb		*res;

  if (!(s_expr = get_expr_lst(str, base, ops, len)))
    {
      return (0);
    }
  res = calc_expr(s_expr, ops, base, len[0]);
  if (zero_check(res, base[0], ops[3], ops[2]))
    {
      *res->nb = '0';
      res->len = 1;
    }
  *(res->nb + res->len) = 0;
  return (res);
}
