/*
** lst_new_data.c for lib in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec  1 19:50:50 2014
** Last update Mon Dec  1 19:51:29 2014 
*/

#include <my.h>

t_lst		*lst_new_data(void *data, size_t data_len)
{
  t_lst		*new;

  if ((new = malloc(sizeof(*new))))
    {
      new->next = NULL;
      new->prev = NULL;
      if ((new->blk.data = malloc(data_len)))
	{
	  new->blk.data = data;
	  new->blk.len = data_len;
	}
      else
	{
	  free(new);
	  new = NULL;
	}
    }
  return (new);
}
