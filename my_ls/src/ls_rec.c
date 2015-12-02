/*
** ls_rec.c for my_ls in /home/k6/rendu/PSU_2014_my_ls
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov 30 17:23:15 2014 Cano Chloe
** Last update Sun Nov 30 17:39:14 2014 Cano Chloe
*/

#include <my_ls.h>

static void	next_free(t_lst **s_lst)
{
  t_lst		*tmp;

  tmp = *s_lst;
  *s_lst = (*s_lst)->next;
  free(tmp->blk.data);
  free(tmp);
}

static t_blk	*init_rec(int *idx, char **filename, t_lst *p_lst, int *len)
{
  t_blk		*blk;

  *idx = 0;
  blk = &p_lst->blk;
  *filename = ENTRY(blk)->path;
  *filename += get_filename_idx(*filename);
  my_bzero(len, sizeof(len[0]) * 6);
  return (blk);
}

int		ls_rec(t_lst *p_lst, int opt, int *nb_files)
{
  t_lst		*dir;
  int		idx;
  char		*filename;
  int		len[6];
  t_blk		*blk;

  while (p_lst)
    {
      blk = init_rec(&idx, &filename, p_lst, len);
      if (!(S_ISLNK(ENTRY(blk)->stat.st_mode)))
	{
	  if (!((!my_strncmp(filename, ".", 2) && (p_lst->next || p_lst->prev))
		|| !my_strncmp(filename, "..", 3)) && !(dir = NULL))
	    {
	      print_dir_name(blk, nb_files);
	      if (get_dir_entries(blk, &dir, opt, len))
		{
		  ls_files(&dir, opt, 1, len);
		  ls_rec(dir, opt, nb_files);
		}
	    }
	}
      next_free(&p_lst);
    }
  return (0);
}
