/*
** is_op.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 13:35:01 2014
** Last update Sun Nov  9 17:27:00 2014 Cano Chloe
*/

#include <eval_expr.h>

int		is_op(char c, char *ops)
{
  int		idx;

  idx = -1;
  while (ops[++idx])
    {
      if (ops[idx] == c)
	return (1);
    }
  return (-1);
}
