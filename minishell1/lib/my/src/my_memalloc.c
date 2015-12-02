/*
** my_memalloc.c for libmy in /home/cano_c/my_select
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Jan  7 16:42:32 2015
** Last update Fri Jan 30 18:45:12 2015 
*/

#include <my.h>

void		*my_memalloc(size_t len)
{
  void		*new;

  if ((new = malloc(len)))
    my_bzero(new, len);
  else
    errno = E_OOM;
  return (new);
}
