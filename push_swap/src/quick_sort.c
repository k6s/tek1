/*
** quick_sort.c for push_swap.c in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Dec  4 11:33:41 2014
** Last update Thu Dec  4 11:53:16 2014 
*/

#include <push_swap.h>

int		set_piv(size_t idx, size_t nb_elem, int UN op)
{
  size_t	piv;
  t_lst		*p;
  size_t	current;

  piv = (nb_elem - idx + 1) / 2 + (nb_elem - idx + 1) % 2;
  current = 0;
  while (current < idx)
    {
      pb(op);
      ++current;
    }
  current = 0;
  p = *s_la(NULL);
  while (current < piv)
    {
      p = p->prev;
      ++current;
    }
  return (*(int *)(p->blk.data));
}

static size_t	do_sort(size_t idx, size_t nb_elem, int UN op)
{
  int		piv_val;
  size_t	new_piv;
  t_lst		**l_a;

  piv_val = set_piv(idx, nb_elem, op);
  l_a = s_la(NULL);
  new_piv = idx;
  while (idx <= nb_elem)
    {
      if (*(int *)((*l_a)->blk.data) < piv_val)
	{
	  pa(op);
	  sa(op);
	  pb(op);
	  ++new_piv;
	}
      else if (*(int *)((*l_a)->blk.data) == piv_val)
	{
	  pb(op);
	  rb(op);
	}
      else
	ra(op);
      ++idx;
    }
  rrb(op);
  while (pa(op))
    ;
  return (new_piv);
}

void		quicksort(size_t idx, size_t nb_elem, int UN op)
{
  size_t	piv_idx;

  if (idx < nb_elem)
    {
      piv_idx = do_sort(idx, nb_elem, op);
      quicksort(idx, piv_idx - 1, op);
      quicksort(piv_idx + 1, nb_elem, op);
    }
}
