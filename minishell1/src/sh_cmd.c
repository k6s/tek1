/*
** sh_cmd.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 19 16:21:51 2015
** Last update Tue Feb  3 11:54:53 2015 
*/
#include <minishell1.h>

static char		process_line(t_term *s_term, char *line)
{
  t_prog		*s_prog;
  char			**av;

  if (*line && (av = str_split_whitespc(line)))
    {
      if ((s_prog = find_prog(s_term->progs, av[0])))
	{
	  if (s_prog->builtfp)
	    return (exe_builtin(s_prog, av, s_term));
	  else
	    return (exe_cmd(s_prog, av, s_term->environ));
	}
      else
	write(2, "command not found\n", 19);
      free_strtab(av);
    }
  return (0);
}

char			*concat_buff(t_buff *s_buff)
{
  size_t		tlen;
  t_buff		*b_buff;
  char			*line;

  tlen = 0;
  b_buff = s_buff;
  while (s_buff)
    {
      tlen += s_buff->len;
      s_buff = s_buff->next;
    }
  if ((line = malloc(sizeof(*line) * (tlen + 1))))
    {
      tlen = 0;
      while (b_buff)
	{
	  my_memcpy(line + tlen, b_buff->buff, b_buff->len);
	  tlen += b_buff->len;
	  s_buff = b_buff;
	  b_buff = b_buff->next;
	}
      line[tlen] = 0;
    }
  return (line);
}

int			add_char(t_buff **c_buff, char c)
{
  t_buff		*s_buff;

  if ((*c_buff)->next)
    tputs(tgetstr("im", NULL), 0, &tput_putc);
  write(1, &c, 1);
  tputs(tgetstr("ei", NULL), 0, &tput_putc);
  if ((*c_buff)->len == BUFF_SIZE)
    {
      s_buff = (*c_buff)->next;
      if (((*c_buff)->next = my_memalloc(sizeof(**c_buff))))
	{
	  (*c_buff)->next->prev = *c_buff;
	  *c_buff = (*c_buff)->next;
	  (*c_buff)->next = s_buff;
	  if (s_buff)
	    s_buff->prev = *c_buff;
	}
      else
	return (-1);
    }
  (*c_buff)->buff[(*c_buff)->len] = c;
  ++(*c_buff)->len;
  return (0);
}

t_hist			*add_hist(t_buff *new, t_hist **hist)
{
  t_hist		*nhist;

  if ((nhist = my_memalloc(sizeof(*nhist))))
    {
      nhist->buff = new;
      if (*hist)
	{
	  while ((*hist)->next)
	    *hist = (*hist)->next;
	  if ((*hist)->next)
	    *hist = (*hist)->next;
	  (*hist)->next = nhist;
	  nhist->prev = *hist;
	  *hist = (*hist)->next;
	}
      else
	*hist = nhist;
    }
  return (nhist);
}

int			next_line(t_term *s_term, t_line *s_line,
				  t_buff **s_buff)
{
  write(1, ":> ", 3);
  if ((s_line->line && *s_line->line->buff) || !s_line->line)
    {
      if (!(s_line->line = my_memalloc(sizeof(*s_line->line))))
	return (-1);
      if (!(add_hist(s_line->line, &s_line->hist)))
	return (-1);
    }
  *s_buff = s_line->line;
  s_term->line = s_line;
  return (0);
}

char			get_user_input(t_term *s_term, t_buff *s_buff,
				       t_line *s_line)
{
  char			c[4];
  ssize_t		read_len;

  my_bzero(c, 4);
  while (!s_term->end && (read_len = read(0, c, 3)) > 0
	 && c[0] != '\n' && c[0])
    {
      if (c[0] >= ' ' && c[0] <= '~')
	{
	  if (add_char(&s_buff, *c) < 0)
	    return (-1);
	}
      else
	special_key(&s_buff, s_line, c, s_term);
      my_bzero(c, 4);
    }
  write(1, "\n", 1);
  return (0);
}

int			shell_readloop(t_term *s_term)
{
  t_buff		*s_buff;
  int			ret;
  t_line		*s_line;

  if (!(s_line = my_memalloc(sizeof(*s_line))))
    return (-1);
  while (!s_term->end)
    {
      if (!next_line(s_term, s_line, &s_buff))
	{
	  if (get_user_input(s_term, s_buff, s_line) < -1)
	    return (-2);
	  if ((s_line->s = concat_buff(s_line->line)))
	    {
	      if ((ret = process_line(s_term, s_line->s)) < -1)
		return (-2);
	      free(s_line->s);
	      s_line->s = NULL;
	    }
	}
      else
	s_term->end = 1;
    }
  return (0);
}
