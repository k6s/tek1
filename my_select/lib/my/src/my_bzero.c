/*
** my_bzero.c for my_bzero in /home/cano_c/rendu/Piscine_C_J12/lib/my
** 
** Made by
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Oct 21 09:37:35 2014
** Last update Tue Oct 21 17:08:37 2014 Cano Chloe
*/

void			my_bzero(char *mem, unsigned int len)
{
  unsigned int		idx;

  idx = 0;
  while (idx < len)
    *(mem + idx++) = 0;
}
