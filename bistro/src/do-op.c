/*
** main.c for do-op in /home/cano_c/rendu/Piscine_C_J11
** 
** Made by
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Oct 20 10:48:50 2014
** Last update Sun Nov  9 17:25:57 2014 Cano Chloe
*/

#include <do-op.h>

t_nb		*do_op(t_op *s_op, char *ops)
{
  t_nb		*(*op_ptr[256])(t_nb *, t_nb *, t_base *, char *);
  t_nb		*ret;
  t_base	s_base;

  ret = NULL;
  s_base.base = s_op->base;
  s_base.base_len = s_op->base_len;
  op_ptr[(int)ops[3]] = inf_sub;
  op_ptr[(int)ops[2]] = inf_add;
  op_ptr[(int)ops[5]] = inf_div;
  op_ptr[(int)ops[4]] = inf_mul;
  op_ptr[(int)ops[6]] = inf_mod;
  ret = op_ptr[(int)s_op->op](s_op->n1, s_op->n2, &s_base, ops);
  return (ret);
}
