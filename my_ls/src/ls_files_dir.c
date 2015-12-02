/*
** ls_files_dir.c for my_ls in /home/k6/rendu/PSU_2014_my_ls
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov 30 17:32:46 2014 Cano Chloe
** Last update Sun Nov 30 17:39:26 2014 Cano Chloe
*/

#include <my_ls.h>

void		print_files(t_lst **s_lst, t_lst **p_lst, int opt, int *len)
{
  t_blk		*blk;
  t_lst		*tmp;

  blk = &(*p_lst)->blk;
  print_entry(blk, opt, len);
  free(blk->data);
  tmp = (*p_lst)->next;
  if (*s_lst == *p_lst)
    *s_lst = (*s_lst)->next;
  lst_rm(s_lst, *p_lst);
  *p_lst = tmp;
}

int		ls_files(t_lst **s_lst, int opt, char print_dir, int *len)
{
  t_blk		*blk;
  t_lst		*tmp;
  t_lst		*p_lst;
  int		nb_files;

  p_lst = *s_lst;
  nb_files = 0;
  while (p_lst)
    {
      blk = &p_lst->blk;
      if (!S_ISDIR(ENTRY(blk)->stat.st_mode))
	{
	  print_files(s_lst, &p_lst, opt, len);
	  ++nb_files;
	}
      else
	{
	  tmp = p_lst->next;
	  blk = &p_lst->blk;
	  if (print_dir)
	    print_entry(blk, opt, len);
	  p_lst = tmp;
	}
    }
  return (nb_files);
}

void		ls_dir(t_blk *blk, int opt, int nb_files)
{
  t_lst		*tmp;
  t_lst		*p_lst;
  int		len[6];

  p_lst = NULL;
  my_bzero(len, 6 * sizeof(len[0]));
  if (get_dir_entries(blk, &p_lst, opt, len))
    {
      if (nb_files)
	print_dir_name(blk, &nb_files);
      while (p_lst)
	{
	  blk = &p_lst->blk;
	  print_entry(blk, opt, len);
	  free(blk->data);
	  tmp = p_lst;
	  p_lst = p_lst->next;
	  free(tmp);
	}
    }
}
