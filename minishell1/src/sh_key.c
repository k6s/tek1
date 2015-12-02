/*
** sh_key.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 26 02:35:13 2015
** Last update Sat Jan 31 22:26:13 2015 
*/
#include <minishell1.h>

int			cu_left(t_buff **c_buff, t_buff **b_buff)
{
  if ((*c_buff)->prev)
    {
      tputs(tgetstr("le", NULL), 0, &tput_putc);
      *c_buff = (*c_buff)->prev;
    }
  else
    {
      if ((*c_buff)->len)
	{
	  if (!((*c_buff)->prev = my_memalloc(sizeof(**c_buff))))
	    return (-1);
	  (*c_buff)->prev->next = *c_buff;
	  *c_buff = (*c_buff)->prev;
	  *b_buff = *c_buff;
	  tputs(tgetstr("le", NULL), 0, &tput_putc);
	}
    }
  return (0);
}

int			cu_right(t_buff **c_buff, t_buff UN **b_buff)
{
  if ((*c_buff)->next)
    {
      tputs(tgetstr("nd", NULL), 0, &tput_putc);
      *c_buff = (*c_buff)->next;
    }
  return (0);
}

int			cu_del(t_buff **c_buff, t_buff UN **b_buff)
{
  t_buff		*tmp;

  if ((*c_buff)->prev)
    {
      tmp = *c_buff;
      (*c_buff)->prev->next = (*c_buff)->next;
      if ((*c_buff)->next)
	(*c_buff)->next->prev = (*c_buff)->prev;
      *c_buff = (*c_buff)->prev;
      free(tmp);
      tputs(tgetstr("le", NULL), 0, &tput_putc);
      tputs(tgetstr("dc", NULL), 0, &tput_putc);
    }
  else if ((*c_buff)->len)
    {
      my_bzero((*c_buff)->buff, BUFF_SIZE);
      (*c_buff)->len = 0;
      	  tputs(tgetstr("le", NULL), 0, &tput_putc);
      tputs(tgetstr("dc", NULL), 0, &tput_putc);
    }
  return (0);
}

int		cu_do(t_buff **c_buff, t_buff **b_buff, t_hist **hist)
{
  t_buff	*s_buff;

  if (*hist && (*hist)->next)
    {
      *hist = (*hist)->next;
      tputs(tgetstr("cr", NULL), 0, &tput_putc);
      tputs(tgetstr("ce", NULL), 0, &tput_putc);
      write(1, ":> ", 3);
      *c_buff = (*hist)->buff;
      *b_buff = (*hist)->buff;
      while ((*c_buff)->next)
	{
	  write(1, (*c_buff)->buff, (*c_buff)->len);
	  *c_buff = (*c_buff)->next;
	}
      write(1, (*c_buff)->buff, (*c_buff)->len);
    }
  return (0);
}

int		cu_up(t_buff **c_buff, t_buff **b_buff, t_hist **hist)
{
  t_buff	*s_buff;

  if (*hist && (*hist)->prev)
    {
      *hist = (*hist)->prev;
      tputs(tgetstr("cr", NULL), 0, &tput_putc);
      tputs(tgetstr("ce", NULL), 0, &tput_putc);
      write(1, ":> ", 3);
      *c_buff = (*hist)->buff;
      *b_buff = (*hist)->buff;
      while ((*c_buff)->next)
	{
	  write(1, (*c_buff)->buff, (*c_buff)->len);
	  (*c_buff) = (*c_buff)->next;
	}
      write(1, (*c_buff)->buff, (*c_buff)->len);
    }
  return (0);
}

int			special_key(t_buff **s_buff, t_line *s_line, char *key,
				    t_term *s_term)
{
  if (key[2] == K_LE)
    return (cu_left(s_buff, &s_line->line));
  else if (key[2] == K_RI)
    return (cu_right(s_buff, &s_line->line));
  else if (key[0] == K_DEL)
    return (cu_del(s_buff, &s_line->line));
  else if (key[2] == K_UP)
    return (cu_up(s_buff, &s_line->line, &s_line->hist));
  else if (key[2] == K_DO)
    return (cu_do(s_buff, &s_line->line, &s_line->hist));
  else if (key[0] == 4)
  {
    if (s_term->line && s_term->line->hist)
      clear_line(s_term->line->hist->buff);
    s_term->end = 1;
  }
  return (0);
}
