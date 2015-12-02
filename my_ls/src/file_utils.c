/*
** file_utils.c for my_ls in /home/k6/rendu/PSU_2014_my_ls
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov 30 17:27:20 2014 Cano Chloe
** Last update Sun Nov 30 17:38:22 2014 Cano Chloe
*/

#include <my_ls.h>

size_t		get_filename_idx(char *path)
{
  size_t       	idx;
  size_t	end;

  idx = 0;
  end = 0;
  while (path[idx + end])
    {
      end = 0;
      while (path[idx + end] && path[idx + end] != '/')
	++end;
      if (path[idx + end] && path[idx + end + 1])
	{
	  idx += end + 1;
	  end = 0;
	}
      else if (path[idx + end])
	++end;
    }
  return (idx);
}

void		print_dir_name(t_blk *blk, int *nb_files)
{
  if (*nb_files < 0)
    my_putchar('\n');
  my_putstr(ENTRY(blk)->path);
  my_putstr(":\n");
  *nb_files = -1;
}

void		print_lnk(t_blk *blk)
{
  my_putstr(ENTRY(blk)->path);
  my_putstr(" -> ");
  my_putstr(ENTRY(blk)->lnk);
}
