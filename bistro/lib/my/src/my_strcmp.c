/*
** my_strcmp.c for lib in /home/cano_c/rendu/ELEM/Bistromathique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 13:17:54 2014
** Last update Sun Nov  9 13:18:06 2014 
*/

int		my_strcmp(char *s1, char *s2)
{
  int		ret;

  if (*s1 == *s2 && *s1 && *s2)
    return (my_strcmp(++s1, ++s2));
  ret = *s1 - *s2 > 0 ? 1 : *s1 - *s2;
  ret = ret < 0 ? -1 : ret;
  return (ret);
}
