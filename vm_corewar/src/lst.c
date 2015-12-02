/*
** lst.c for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Mar 18 17:22:24 2015 
** Last update Thu Apr  9 23:27:32 2015 
*/
#include <vm.h>

void		lst_append(t_lst **lst, t_lst *new)
{
  t_lst		*cu_lst;

  if (!*lst)
    *lst = new;
  else
    {
      cu_lst = *lst;
      while (cu_lst->next)
	cu_lst = cu_lst->next;
      cu_lst->next = new;
    }
}

t_lst		*new_lst(size_t data_len)
{
  t_lst		*new;

  if (!(new = malloc(sizeof(*new))))
    return (NULL);
  my_bzero(new, sizeof(*new));
  if (data_len && !(new->data = malloc(sizeof(char) * data_len)))
    return (NULL);
  return (new);
}
