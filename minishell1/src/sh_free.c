/*
** sh_free.c for minishell1 in /home/cano_c/rendu/UNIX/my_select/minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Jan 31 22:22:04 2015
** Last update Sat Jan 31 22:24:40 2015 
*/
#include <minishell1.h>

void			free_strtab(char **strtab)
{
  char			**stab;

  stab = strtab;
  if (stab)
    {
      while (*stab)
	{
	  free(*stab);
	  ++stab;
	}
      free(strtab);
    }
}

void			free_progs(t_progs *progs)
{
  int			c;

  c = -1;
  if (progs)
    {
      while (c <= '~')
	if (progs->next[++c])
	  free_progs(progs->next[(int)(c)]);
      free(progs->prog);
      free(progs);
    }
}

void			free_line(t_line *s_line)
{
  t_hist		*htmp;

  if (s_line->hist)
    {
      while (s_line->hist->prev)
	s_line->hist = s_line->hist->prev;
      if (s_line->hist->prev)
	s_line->hist = s_line->hist->prev;
      while (s_line->hist)
	{
	  htmp = s_line->hist;
	  s_line->hist = s_line->hist->next;
	  clear_line(htmp->buff);
	  free(htmp->buff);
	  free(htmp);
	}
    }
  free(s_line->s);
  free(s_line);
}

void			free_stuff(t_term *s_term)
{
  if (s_term->progs)
    free_progs(s_term->progs);
  free_strtab(s_term->environ);
  if (s_term->line)
    free_line(s_term->line);
}
