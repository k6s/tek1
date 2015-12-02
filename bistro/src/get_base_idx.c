/*
** get_idx_base.c for Bistro in ~/rendu/ELEM/Bistromathique/src/op_tests
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov  3 17:05:49 2014
** Last update Sun Nov  9 17:26:08 2014 Cano Chloe
*/

#include <eval_expr.h>

int		get_base_idx(char c, char *base)
{
  int		idx;

  idx = -1;
  while (base[++idx])
    {
      if (base[idx] == c)
	return (idx);
    }
  return (-1);
}
