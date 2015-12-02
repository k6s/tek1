/*
** my_strlen.c for lib in /home/cano_c/rendu/ELEM/Bistromathique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 13:18:21 2014
** Last update Sun Nov  9 13:18:30 2014 
*/

int			my_strlen(char *str)
{
  char			*s;

  s = str;
  if (s)
    {
      while (*s)
	++s;
    }
  return (s - str);
}
