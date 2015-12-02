/*
** parse_par.c for Bistro in /home/k6/rendu/Bistromathique
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov  9 15:48:33 2014 Cano Chloe
** Last update Sun Nov  9 15:51:08 2014 Cano Chloe
*/

#include <eval_expr.h>

char		p_parb(t_bistro *bistro, t_expr **stack, char UN *ctt)
{
  push(stack, bistro->ops[0], NULL, TYPE_PAR_BEG);
  ++(bistro->str);
  ++bistro->par;
  return (TYPE_PAR_BEG);
}

static void	go_to_end(t_expr **tmp)
{
  while (*tmp && (*tmp)->next)
    *tmp = (*tmp)->next;
}

char		p_pare(t_bistro *bistro, t_expr **stack, char *ctt)
{
  t_expr	*popped;
  t_expr	*tmp;

  popped = NULL;
  tmp = bistro->s_expr;
  go_to_end(&tmp);
  while (!popped || popped->elem != bistro->ops[0])
    {
      if (!(popped = pop(stack)))
	return (p_e(bistro, stack, ctt));
      if (popped->elem != bistro->ops[0])
	{
	  if (!tmp)
	    bistro->s_expr = popped;
	  else
	    {
	      tmp->next = popped;
	      tmp->next->prev = tmp;
	      tmp = tmp->next;
	    }
	}
    }
  ++(bistro->str);
  --bistro->par;
  return (TYPE_PAR_END);
}
