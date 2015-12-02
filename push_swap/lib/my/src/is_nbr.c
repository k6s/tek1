/*
** is_nbr.c for lib in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec  1 20:27:34 2014
** Last update Mon Dec  1 20:28:49 2014 
*/

char		is_nbr(char *s)
{
  char		ok;

  ok = 0;
  while (*s == '-' || *s == '+')
    ++s;
  while (*s)
    {
      if (*s > '9' || *s < '0')
	return (0);
      ++s;
      ok = 1;
    }
  return (ok);
}
