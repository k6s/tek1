/*
** format_output.c for printf in ~/rendu/UNIX/PSU_2014_my_printf/src/printf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 07:57:43 2014
** Last update Sun Nov 16 20:18:22 2014 Cano Chloe
*/

#include <my.h>

int		spc_padding(size_t plen, ssize_t width, char fill)
{
  ssize_t	i;

  i = -1;
  if (width > (ssize_t)plen)
    {
      while (++i < (width - plen))
	my_putchar(fill);
    }
  return (i > 0 ? i : 0);
}
