/*
** padding.c for my_ls in /home/k6/rendu/PSU_2014_my_ls
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov 30 17:37:12 2014 Cano Chloe
** Last update Sun Nov 30 17:37:23 2014 Cano Chloe
*/

#include <my_ls.h>

void		get_padding(t_blk *blk, int *len)
{
  int		idx;

  idx = -1;
  while (++idx < 5)
    {
      if (ENTRY(blk)->len[idx] > len[idx])
	len[idx] = ENTRY(blk)->len[idx];
    }
  len[idx] += ENTRY(blk)->len[idx] / 2;
}

void		get_files_padding(t_lst *s_lst, int *len)
{
  t_blk		*blk;
  int		idx;

  while (s_lst)
    {
      blk = &s_lst->blk;
      if (!S_ISDIR(ENTRY(blk)->stat.st_size))
	{
	  idx = -1;
	  while (++idx < 5)
	    if (len[idx] < ENTRY(blk)->len[idx])
	      len[idx] = ENTRY(blk)->len[idx];
	}
      s_lst = s_lst->next;
    }
}
