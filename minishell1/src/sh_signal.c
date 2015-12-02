/*
** sh_signal.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 19 16:16:41 2015 
** Last update Sat Jan 31 22:45:01 2015 
*/
#include <minishell1.h>

void			handle_term(int UN sig)
{
  t_term		*s_term;

  s_term = static_term(NULL);
  s_term->end = 1;
  init_signals();
}

void			clear_line(t_buff *p_buff)
{
  t_buff		*tmp;

  tmp = p_buff;
  p_buff = p_buff->next;
  tmp->next = NULL;
  my_bzero(tmp->buff, BUFF_SIZE);
  tmp->len = 0;
  while (p_buff)
    {
      tmp = p_buff;
      p_buff = p_buff->next;
      free(tmp);
    }
}

void			clear_hist(t_hist *hist)
{
  t_hist		*tmp;

  while (hist->next)
    hist = hist->next;
  if (hist->next)
    hist = hist->next;
  while (hist)
    {
      tmp = hist;
      clear_line(hist->buff);
      free(hist->buff);
      hist = hist->next;
      free(tmp);
    }
}

void			handle_int(int UN signal)
{
  t_term		*s_term;
  t_hist		*tmp;

  if ((s_term = static_term(NULL)))
    {
      write(1, "^C", 2);
      if (s_term->line && s_term->line->line)
	{
	  tmp = s_term->line->hist;
	  while (tmp->next)
	    tmp = tmp->next;
	  if (tmp->next)
	    tmp = tmp->next;
	  clear_line(tmp->buff);
	  s_term->line->line = tmp->buff;
	}
    }
  init_signals();
}

void			init_signals(void)
{
  signal(SIGTERM, &handle_term);
  signal(SIGINT, &handle_int);
  signal(SIGQUIT, &handle_term);
  signal(SIGHUP, &handle_term);
}
