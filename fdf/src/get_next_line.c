/*
** get_next_line.c for get_next_line in ~/rendu/ELEM/CPE_2014_get_next_line
** 
** Made by Chloe  Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 17 11:15:36 2014
** Last update Sun Nov 23 23:18:14 2014 Cano Chloe
*/

#include <get_next_line.h>

t_lst		*read_again(t_lst **lst, const int fd, ptrdiff_t *off)
{
  t_lst		*tmp;
  t_lst		*new;
  t_lst		*s_eol;
  int		read_len;

  tmp = *lst;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!(new = malloc(sizeof(*new))))
    return (NULL);
  new->next = NULL;
  while ((read_len = read(fd, new->blk.data, READ_LEN)) > 0)
    {
      if (read_len < 0)
	return ((void *)-1);
      new->blk.len = read_len;
      next_elem(lst, new, &tmp);
      if ((s_eol = lst_memchr(new, EOL, off)))
	return (s_eol);
      if (!(new = malloc(sizeof(*new))))
	return (NULL);
      new->next = NULL;
    }
  return (NULL);
}

char		*new_line(t_lst **lst, t_lst *s_eol, ptrdiff_t off)
{
  t_lst		*p_lst;
  size_t	len;

  p_lst = *lst;
  len = 0;
  while (p_lst != s_eol)
    {
      len += p_lst->blk.len;
      p_lst = p_lst->next;
    }
  return (malloc(len + off + 1));
}

size_t		copy_end(t_lst **lst, t_lst *s_eol, ptrdiff_t off, size_t idx)
{
  t_lst		*tmp;

  if (*lst == s_eol)
    {
      idx = 0;
      while ((off + ++idx) < (*lst)->blk.len)
	(*lst)->blk.data[idx - 1] = (*lst)->blk.data[off + idx];
      (*lst)->blk.len = idx - 1;
    }
  else
    {
      tmp = *lst;
      *lst = (*lst)->next;
      free(tmp);
    }
  return (idx);
}

char		*concat_lst(t_lst **lst, t_lst *s_eol, ptrdiff_t off)
{
  size_t	len;
  size_t	idx;
  t_lst		*tmp;
  char		*line;

  line = new_line(lst, s_eol, off);
  len = 0;
  while (*lst != s_eol)
    {
      idx = -1;
      while (++idx < (*lst)->blk.len)
	*(line + len + idx) = (*lst)->blk.data[idx];
      len += idx;
      tmp = *lst;
      *lst = (*lst)->next;
      free(tmp);
    }
  idx = -1;
  while (++idx < off)
    *(line + len + idx) = (*lst)->blk.data[idx];
  *(line + len + idx) = 0;
  idx = copy_end(lst, s_eol, off, idx);
  return (line);
}

char		*get_next_line(const int fd)
{
  t_lst		**fd_lst = NULL;
  t_lst		*lst;
  t_lst		*s_eol;
  ptrdiff_t	off;
  char		*line;

  if (!(fd_lst = get_fd_tab(fd)) < 0)
    return (NULL);
  lst = fd_lst[fd];
  if (!lst || !(s_eol = lst_memchr(lst, EOL, &off)))
    {
      if (!(s_eol = read_again(&lst, fd, &off)))
	return (NULL);
    }
  line = concat_lst(&lst, s_eol, off);
  fd_lst[fd] = lst;
  return (line);
}
