/*
** lst_swap.c for lib in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap/lib/my
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec  1 17:58:16 2014
** Last update Mon Dec  1 18:45:37 2014 
*/

#include <my.h>

t_lst		*lst_pop(t_lst **stack)
{
  t_lst		*popped;

  popped = NULL;
  if (*stack)
    {
      popped = *stack;
      *stack = (*stack)->prev;
      popped->next = NULL;
      popped->prev = NULL;
      if (*stack)
	(*stack)->next = NULL;
    }
  return (popped);
}

void		lst_push(t_lst **stack, t_lst *elem)
{
  if (*stack)
    {
      (*stack)->next = elem;
      elem->prev = *stack;
      elem->next = NULL;
      *stack = (*stack)->next;
    }
  else
    *stack = elem;
}

char		lst_swap(t_lst **stack)
{
  t_lst		*first;
  t_lst		*next;

  if (*stack && (*stack)->prev)
    {
      first = lst_pop(stack);
      next = lst_pop(stack);
      lst_push(stack, next);
      lst_push(stack, first);
      return (1);
    }
  return (0);
}

char		lst_rot(t_lst **stack)
{
  t_lst		*tmp;
  t_lst		*p_stack;

  if (*stack && (*stack)->prev)
    {
      tmp = lst_pop(stack);
      p_stack = *stack;
      while (p_stack->prev)
	p_stack = p_stack->prev;
      p_stack->prev = tmp;
      tmp->next = p_stack;
      return (1);
    }
  return (0);
}

char		lst_rrot(t_lst **stack)
{
  t_lst		*p_stack;
  t_lst		*tmp;

  if (*stack && (*stack)->prev)
    {
      p_stack = *stack;
      while (p_stack->prev)
	p_stack = p_stack->prev;
      tmp = p_stack;
      p_stack->next->prev = NULL;
      p_stack->next = NULL;
      lst_push(stack, tmp);
      return (1);
    }
  return (0);
}
