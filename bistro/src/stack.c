/*
** stack.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 12:49:18 2014
** Last update Sun Nov  9 17:28:03 2014 Cano Chloe
*/

#include <eval_expr.h>

t_expr		*new_elem(int elem, char type)
{
  t_expr	*new;

  if ((new = malloc(sizeof(*new))))
    {
      new->elem = elem;
      new->type = type;
      new->next = NULL;
      new->prev = NULL;
    }
  return (new);
}

int		to_expr(t_expr **s_expr, t_nb *nb, char type)
{
  t_expr	*new;
  t_expr	*tmp;

  if ((new = new_elem(1, type)))
    {
      new->nb = nb;
      if (!*s_expr)
	*s_expr = new;
      else
	{
	  tmp = *s_expr;
	  while (tmp->next)
	    tmp = tmp->next;
	  tmp->next = new;
	  tmp->next->prev = tmp;
	}
      return (1);
    }
  return (0);
}

t_expr		*push(t_expr **stack, char op, t_nb *nb, char type)
{
  t_expr	*new;

  if ((new = new_elem(op, type)))
    {
      if (type == NUM)
	new->nb = nb;
      if (!*stack)
	*stack = new;
      else
	{
	  (*stack)->next = new;
	  new->prev = *stack;
	  *stack = (*stack)->next;
	}
    }
  return (new);
}

t_expr		*pop(t_expr **stack)
{
  t_expr	*elem;

  elem = NULL;
  if (*stack)
    {
      elem = *stack;
      *stack = (*stack)->prev;
      if (*stack)
	(*stack)->next = NULL;
      elem->prev = NULL;
    }
  return (elem);
}

void		stack_to_expr(t_expr **stack, t_expr *expr)
{
  while (expr->next)
    expr = expr->next;
  while (*stack)
    {
      expr->next = pop(stack);
      expr->next->prev = expr;
      expr = expr->next;
      expr->next = NULL;
    }
}
