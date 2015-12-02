/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/cano_c/lib
** 
** Made by
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Oct 10 10:45:03 2014
** Last update Mon Oct 20 22:16:29 2014 Cano Chloe
*/
#include <my.h>

char		is_alnum(char c)
{
  if ((c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z')
      || (c >= '0' && c <= '9'))
    return (1);
  return (0);
}

int		count_word(char *str)
{
  int		size;
  char		is_word;

  size = 0;
  while (*str)
    {
      is_word = 0;
      while (*str && is_alnum(*str) && (is_word = 1))
	++str;
      size += is_word;
      while (*str && !is_alnum(*str))
	++str;
    }
  return (size);
}

char		*dup_word(char **str)
{
  int		len;
  char		*s;

  len = 0;
  while (*((*str) + len) && is_alnum(*((*str) + len)))
    ++len;
  if ((s = malloc(sizeof(*s) * (len + 1))))
    {
      my_strncpy(s, *str, len);
      *(s + len) = '\0';
      *str += len;
    }
  return (s);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		tab_len;
  int		word_pos;

  tab_len = count_word(str);
  if ((tab = malloc(sizeof(*tab) * (tab_len + 1))))
    {
      tab[tab_len] = 0;
      word_pos = -1;
      while (*str)
	{
	  if (*str && is_alnum(*str))
	    {
	      if (!(tab[++word_pos] = dup_word(&str)))
		return ((char **)0);
	    }
	  while (*str && !is_alnum(*str))
	    ++str;
	}
    }
  return (tab);
}
