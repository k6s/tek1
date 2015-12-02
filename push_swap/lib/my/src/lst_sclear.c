/*
** lst_sclear.c for lib in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec  1 19:51:40 2014
** Last update Mon Dec  1 19:51:55 2014 
*/

#include <my.h>

void		lst_sclear(t_lst **lst)
{
  t_lst		*tmp;
  while (*lst)
    {
      tmp = *lst;
      *lst = (*lst)->prev;
      free(tmp->blk.data);
      free(tmp);
    }
}
