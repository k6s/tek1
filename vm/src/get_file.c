/*
** get_file.c for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Mar 18 17:20:27 2015 
** Last update Wed Mar 18 17:44:34 2015 
*/
#include <vm.h>

static size_t	read_file(int fd, t_lst **lst)
{
  t_lst		*new;
  size_t	read_len;
  size_t	t_len;

  t_len = 0;
  if (!(new = new_lst(BUFF_LEN)))
    return (0);
  while ((read_len = read(fd, new->data, BUFF_LEN)) > 0)
    {
      new->len = read_len;
      t_len += new->len;
      lst_append(lst, new);
      if (!(new = new_lst(BUFF_LEN)))
	return (0);
    }
  free(new->data);
  free(new);
  return (t_len);
}

static void	*lst_concatn(t_lst *lst, size_t t_len)
{
  size_t	len;
  void		*mem;
  t_lst		*tmp;

  len = 0;
  if (!(mem = malloc(sizeof(char) * t_len)))
    return (NULL);
  while (len < t_len)
    {
      my_memcpy((char *)mem + len, lst->data, lst->len);
      tmp = lst;
      len += lst->len;
      lst = lst->next;
      free(tmp->data);
      free(tmp);
    }
  return (mem);
}

void		*get_file_content(int fd, size_t *t_len)
{
  t_lst		*lst_file;

  lst_file = NULL;
  if (!(*t_len = read_file(fd, &lst_file)))
    return (NULL);
  return (lst_concatn(lst_file, *t_len));
}
