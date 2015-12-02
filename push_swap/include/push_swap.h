/*
** push_swap.h for push_swap in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec  1 19:32:47 2014
** Last update Mon Dec  1 19:33:30 2014 
*/

#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_

# include <my.h>

# define O_VERB	1

t_lst		**s_la(t_lst *la);
t_lst		**s_lb(t_lst *lb);

int		sa(int op);
int		sb(int op);
int		ss(int op);
int		pa(int op);
int		pb(int op);
int		ra(int op);
int		rb(int op);
int		rr(int op);
int		rra(int op);
int		rrb(int op);
int		rrr(int op);

void		quicksort(size_t idx, size_t nb_elem, int UN op);

#endif /* !PUSH_SWAP_H_ */
